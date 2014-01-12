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
    using accept_if<T,C>::accept;
    T *a;
    size_t sz;
public:
    bubble_sort(void):a(NULL), sz(0) {};
    void init (T *ar, size_t s)

    {
        a = ar;
        sz = s;
    };
    void end(void);// { };
    virtual const char *get_name(void) const
    {
        return "Bubble Sort";
    };
    void do_work(void)
    {
       C c;
       for (size_t j = sz; j != 0; --j)
           for (size_t i = 0; i + 1< j; ++i)
           {
              if (c(a[i+1], a[i]))
                  std::swap(a[i], a[i+1]);
          }
     };

    void accept(visitor<T,C> *v)
    {
        v->visit(this);
    };
};
#endif
