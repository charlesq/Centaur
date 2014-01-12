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

#define BASE 10
    T * a, * h;
    size_t sz;
    size_t acc[10];
public:
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
};
#endif
