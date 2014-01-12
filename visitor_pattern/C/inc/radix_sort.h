#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__
#include <inc/accept_if.h>
#include <stdint.h>
#include <stddef.h>
/* a concrete element class in the visitor 
   pattern.
 */
template <typename T, typename C>
class radix_sort: public accept_if<T, C>
{
    using accept_if<T,C>::accept;
#define BASE 10
    T * a, * h;
    size_t sz;
    size_t acc[10];
public:
    radix_sort(void):a(NULL), sz(0) {};
    virtual void init(T *ar, size_t s)
    {
        a = ar;
        sz = s; 
        h = new T[sz];
    }
    virtual const char *get_name(void) const
    {
        return "Radix Sort";
    };
    virtual void do_work(void);
    virtual void end(void)
    {
        delete [] h;
    };
    void accept(visitor<T,C> *v)
    {
        v->visit(this);
    };
};
#endif
