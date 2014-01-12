#ifndef __INSERT_SORT_H__
#define __INSERT_SORT_H__
#include <inc/accept_if.h>
#include <stdint.h>
#include <stddef.h>
#include <algorithm>
/* a concrete element class in the visitor 
   pattern.
 */
template <typename T, typename C>
class insert_sort: public accept_if<T, C>
{
   T *a;
   size_t sz;
public:
    void init(T*ar, size_t s)
    {
        a = ar;
        sz = s;
    };
    void end(void) {};
    virtual const char *get_name(void) const
    {
        return "Insert Sort";
    };
    virtual void do_work(void);
};
#endif
