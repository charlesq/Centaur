#ifndef __ALGORITHMS_H__
#define __ALGORITHMS_H__
#include <inc/insert_sort.h>
#include <inc/bubble_sort.h>
#include <inc/heap_sort.h>
#include <inc/quick_sort.h>
#include <inc/merge_sort.h>
#include <inc/radix_sort.h>
#include <inc/accept_if.h>
#include <vector>
#include <iostream>
/* algorithms class is composed of six 
   elements.
 */
template <typename T, typename C>
class algorithms:public accept_if<T,C>
{
   std::vector<sort *> elements;
public:
   algorithms(void)
   {
       elements.push_back(new quick_sort<T,C>());
       elements.push_back(new heap_sort<T,C> ());
       elements.push_back(new radix_sort<T,C>());
       elements.push_back(new bubble_sort<T,C>());
       elements.push_back(new insert_sort<T,C>());
       elements.push_back(new merge_sort<T,C>());
   };
   accept(visitor<T,C> &v)
   {
      for (auto e: elements)
          e->accept(v); 
      std::cout << "\nhaving tested element sorting algorithms" << std::end;
       
   };
   virtual ~algorithms()
   {
       for (auto e: elements)
           delete e;
       elements.clear();
   };
   
};
#endif
