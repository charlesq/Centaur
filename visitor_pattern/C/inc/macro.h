#ifndef __MACRO_H__
#define __MACRO_H__
#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <inc/heap_sort.h>
#include <inc/insert_sort.h>
#include <inc/bubble_sort.h>
#include <inc/merge_sort.h>
#include <inc/quick_sort.h>
#include <inc/radix_sort.h>
#define VISITOR_BODY()\
                { \
              if (strcmp(s->get_name(), "Radix Sort") == 0 && strcmp(this->get_name(),"pair_visitor") == 0)\
              {\
                  std::cout << s->get_name() << " can not applicalbe to " << this->get_name() << std::endl;\
                  return;\
              }\
              fisher_yates_shuffle();\
              std::cout << "running " << s->get_name() << std::endl;\
              s->init(a, sz);\
              s->do_work();\
              s->end();\
             }

#define VISITOR_IMP(cl, T, C) \
          void  cl::visit(quick_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(heap_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(insert_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(bubble_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(merge_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(radix_sort<T,C> *s)\
          VISITOR_BODY()
/*
#define VISITOR_DECLARE(T, C) \
          virtual void  visit(quick_sort<T,C> *s);\
          virtual void  visit(heap_sort<T,C> *s);\
          virtual void  visit(bubble_sort<T,C> *s);\
          virtual void  visit(radix_sort<T,C> *s);\
          virtual void  visit(merge_sort<T,C> *s);\
          virtual void  visit(insert_sort<T,C> *s);
*/
#endif
