#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__
#include <inc/accept_if.h>
#include <stdint.h>
#include <stddef.h>
#include <algorithm>
/* a concrete element class in the visitor 
   pattern.
 */
template <typename T, typename C>
class bubble_sort: public accept_if<T, C>
{
    T *a;
    size_t sz;
public:
    void init (T *ar, size_t s)
    {
        a = ar;
        sz = s;
    };
    void end(void) { };
    virtual const char *get_name(void) const
    {
        return "Bubble Sort";
    };
    void do_work(void);
};
#endif
