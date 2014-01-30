#ifndef __SKIP_LIST_H__
#define __SKIP_LIST_H__
#include <vector>
#include <cstddef>
#include <cstdint>
#include "node.hpp"
#include <pthread.h>
#include <algorithm>
#include <cstdlib>
#include <limits>
using namespace std;
template <typename T, typename C>
class skip_list
{
   vector<node<T> *> root; 
   const size_t max_level; 
   pthread_rwlock_t lock;
   C cmp;
   vector<node<T>*> cur, prev;
public:
    skip_list(size_t ml):max_level(ml)
    {
        node<T> *n = NULL;
        root.resize(max_level, n);
        pthread_rwlockattr_t attr;
        pthread_rwlockattr_init(&attr);
        pthread_rwlock_init(&lock, &attr);
        cur.resize(max_level, n);
        prev.resize(max_level, n); 
    };
    skip_list(void)
    {
        skip_list(4);
    };
    bool insert(T k)
    {
        node<T> *n = NULL;
        pthread_rwlock_wrlock(&lock);
        std::fill(prev.begin(), prev.end(), n);
        std::fill(cur.begin(), cur.end(), n);
        int level = max_level -1;
        cur[level] = root[level];
        prev[level] = NULL;
        while(level >= 0)
        {
            if(cur[level] == NULL)
            {
                if (prev[level] == NULL)
                {
                    cur[level-1] = root[--level];
                    continue; 
                }
                /* test if prev and cur are adjacent at this layer */
                if (prev[level].next[level] != NULL)
                {
                    /* if not, move cur to prev next */ 
                    cur[level] = prev[level].next[level];
                    continue;
                }
                cur[level-1] = prev[level-1].next[level-1];
                prev[level-1] = prev[level--];  
                continue;
            }
            if(cmp(k, cur[level]->get_key()) == false && cmp(cur[level]->get_key()) == false)
            {
                pthread_rwlock_unlock(&lock);
                return false; 
             }
            if (cmp(k, cur[level]->get_key()))
            {
               if (prev[level] == NULL)
               {
                   cur[level-1] = root[--level];
                   continue;
               } 
               if (prev[level].next[level-1] != cur[level])
               {
                  cur[level-1] = prev[level].next[--level]; 
               } 
               else
               {
                   cur[level-1] = cur[level];
                   prev[level-1] = prev[level-1];
               }
               continue;
            }
            prev[level] = cur[level];
            cur[level] = cur[level].next[level];
        }
        add_node(k);
        pthread_rwlock_unlock(&lock);
        return true;
    };
private:
    void add_node(T k) 
    {
        size_t level = generate_randomized_level();
        node <T> *nd = new node<T>(k, level);
        for (size_t i = 0; i < level; ++i)
        {
            nd.next[i] = cur[i];
            if (prev[i] == NULL)
            {
                root[i] = nd; 
            }
            else
                prev[i].next[i] = nd;
        }
    };
    size_t generate_randomized_level(void) const
    {
       size_t t = rand(), i = 0, j = 2;
       while(++i < max_level && std::numeric_limits<unsigned int>::max() / j >= t)
       {
           j <<= 1;
       }
       return i;
    };
public: 
    virtual ~skip_list()
    {
        pthread_rwlock_destroy(&lock);
    };
};

#endif
