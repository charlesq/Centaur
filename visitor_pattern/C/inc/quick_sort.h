#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__
//#include <inc/sort.h>
#include <stdint.h>
#include <stddef.h>
#include <inc/accept_if.h>
/* quick_sort class is a concrete element in the visitor 
 * pattern.
 */
template <typename T, typename C>
class quick_sort: public accept_if<T, C>
{
    T *a;
    size_t sz;
   /* partition elements in interval [start, end),
      a divide procedure */
   size_t partition(size_t start, size_t end);
   /* the recursive sort procedure */ 
   void sort(size_t s, size_t e);
public:
   virtual const char *get_name(void) const
   {
       return "Quick Sort";
   };
   virtual void do_work(void);
   void init(T* ar, size_t s)
   {
       a = ar;
       sz = s;
   };
   void end(void)
   {
   };
};
#endif
