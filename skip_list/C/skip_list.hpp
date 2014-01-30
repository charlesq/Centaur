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
   size_t num_elems;
   C cmp;
   
   vector<node<T>*> cur, prev;
   void init(void)
   {
      node<T> *n = NULL;
      root.resize(max_level);
      pthread_rwlockattr_t attr;
      pthread_rwlockattr_init(&attr);
      pthread_rwlock_init(&lock, &attr);
      cur.resize(max_level);
      prev.resize(max_level);
      num_elems = 0;
   };
public:
    skip_list(size_t ml):max_level(ml)
    {
       init(); 
    };
    skip_list(void):max_level(4)
    {
        init();
    };
    size_t size(void) const
    {
        return num_elems;
    };
    bool search (T k)
    {
        bool found =  false;
        pthread_rwlock_rdlock(&lock);
        size_t level = max_level;
        node<T> * p = NULL, *c = root[level];   
        while (level >= 0)
        {
           if (level == 0)
           {
               if (c == NULL)
                  break; 
               if (!cmp(c->get_key(), k) && !cmp(k, c->get_key())) 
               {
                   found = true;
                   break;
               }
               break;
           }
           if (c == NULL && p == NULL)
           {
               c = root[--level];
               continue;
           }  
           if (c == NULL)
           {
               c = (p->get_next())[--level];
               continue;
           }
           if (!cmp(c->get_key(), k) && !cmp(k, c->get_key())) 
           {
               pthread_rwlock_unlock(&lock);
               found = true;
               break;
           }
           if (cmp(k, c->get_key()) )
           {
               if (p != NULL && (p->get_next())[level-1] != c)
               {
                  c = (p->get_next())[--level]; 
                  continue;
               }
               if (p == NULL)
               {
                   c = root[--level]; 
               }
               else
               {
                  c = (p->get_next())[ --level];
               }
              continue;
           }
           p =c;
           c = (c->get_next())[level];
        }
   
        pthread_rwlock_unlock(&lock);
        return found;
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
            if (level == 0)
            {
                if (cur[level] != NULL && !cmp(k, cur[level]->get_key()) && !cmp(cur[level]->get_key(),k))
                {
                    pthread_rwlock_unlock(&lock);
                    return false;
                }
                if (cur[level] == NULL)
                   break;
                if (cmp(k, cur[level]->get_key()))
                    break;
                prev[level] = cur[level];
                cur[level] = (cur[level]->get_next())[level];
                continue;
            }
            if(cur[level] == NULL)
            {
                if (prev[level] == NULL)
                {
                    cur[level-1] = root[--level];
                    continue; 
                }
                /* test if prev and cur are adjacent at this layer */
                if ((prev[level]->get_next())[level] != NULL)
                {
                    /* if not, move cur to prev next */ 
                    cur[level] = (prev[level]->get_next())[level];
                    continue;
                }
                cur[level-1] = (prev[level]->get_next())[level-1];
                prev[level-1] = prev[level--];  
                continue;
            }
            if(cmp(k, cur[level]->get_key()) == false && cmp(cur[level]->get_key(),k) == false)
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
               if ((prev[level]->get_next())[level-1] != cur[level])
               {
                  cur[level-1] = (prev[level]->get_next())[--level]; 
               } 
               else
               {
                   cur[level-1] = cur[level];
                   prev[level-1] = prev[level-1];
               }
               continue;
            }
            prev[level] = cur[level];
            cur[level] = (cur[level]->get_next())[level];
        }
        add_node(k);
        std::fill(prev.begin(), prev.end(), n);
        std::fill(cur.begin(), cur.end(), n);

        pthread_rwlock_unlock(&lock);
        return true;
    };
private:
    void add_node(T k) 
    {
        size_t level = generate_randomized_level();
        node <T> *nd = new node<T>(k, level);
        ++num_elems;
        for (size_t i = 0; i < level; ++i)
        {
            (nd->get_next())[i] = cur[i];
            if (prev[i] == NULL)
            {
                root[i] = nd; 
            }
            else
                (prev[i]->get_next())[i] = nd;
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
        node<T> * e = root[0], *e2 = NULL;
        while(e!= NULL)
        {
           e2 = (e->get_next())[0]; 
           delete e;
           e = e2;
        }
        root.clear();
        cur.clear();
        prev.clear();
    };
};

#endif
