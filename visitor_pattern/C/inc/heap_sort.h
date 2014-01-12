#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__
#include <inc/accept_if.h>
#include <stdint.h>
#include <stddef.h>
/* A concrete element class in visitor pattern
 */
template <typename T, typename C>
class heap_sort: public accept_if<T, C>
{
    using accept_if<T,C>::accept;
    T *a;
    size_t sz;
public:
    heap_sort(void):a(NULL), sz(0) {};
    void init(T *ar, size_t s)
    {
        a = ar;
        sz = s;
    };
    void end (void) {};
    /* heapify the given array into a binary heap 
       tree structure
     */
    void heapify(void); 
    /* a recursive procedure to maintain binary heap 
       subtree structure rooted at index didex
       the global tree size is set with the second
       argument.
     */
    void sift_down(size_t eidx, size_t size);
public:
    void do_work(void);
    const char *get_name(void) const 
    {
        return "Heap Sort";
    };
    void accept(visitor<T,C> *v)
    {
        v->visit(this);
    };

};
#endif
