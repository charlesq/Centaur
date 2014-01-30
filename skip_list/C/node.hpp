#ifndef __NODE_H__
#define __NODE_H__
#include <list>
#include <cstddef>
#include <cstdint>
#include <vector>
using namespace std;
template <typename T>
class node
{
    T key;
    vector<node*> next; 
public:
    node(T k, size_t sz):key(k)
    {
        node *n = NULL;
        next.resize(sz);
    };
    node *get_next(size_t sz)
    {
        if (sz >= next.size())
            return NULL;
        return next[sz];
    };
    vector<node<T>*> & get_next(void)
    {
        return next;
    };
    T get_key(void) const
    {
        return key;
    };
    virtual ~node()
    {
        next.clear();
    };
};

#endif
