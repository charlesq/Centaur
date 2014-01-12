#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__
#include <inc/accept_if.h>
#include <stdint.h>
#include <stddef.h>
/* merge_sort class is a concrete element in 
 * visitor pattern.
 */
template <typename T, typename C>
class merge_sort: public accept_if<T,C>
{

    T* a, *h; /* helper memory used in merge procedure */ 
    size_t sz;
    /* merge two already sorted subarrays,
       [s, (s+e)/2) and [(s+e)/2, e).
       This is a Conquer procedure.
     */
    void merge(size_t s, size_t e);
    /* the divide procedure */
    void divide(size_t s, size_t e);
public:
    const char *get_name(void) const { return "Merge Sort"; };
    virtual void init(T*ar, size_t size)
    {
        a = ar;
        sz = size; 
        h = new T[sz];
    };
    virtual void end(void)
    {
        delete [] h;
    };
    virtual void do_work();
};


#endif
