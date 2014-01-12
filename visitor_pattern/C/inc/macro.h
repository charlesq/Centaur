#ifndef __MACRO_H__
#define __MACRO_H__
#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <inc/bubble_sort.h>
#include <inc/insert_sort.h>
#include <inc/quick_sort.h>
#include <inc/merge_sort.h>
#include <inc/radix_sort.h>
#include <inc/heap_sort.h>

#include <src/bubble_sort.cpp>
#include <src/quick_sort.cpp>
#include <src/radix_sort.cpp>
#include <src/heap_sort.cpp>
#include <src/insert_sort.cpp>
#include <src/merge_sort.cpp>

#define VISITOR_BODY()\
           { \
              if (strcmp(s->get_name(), "Radix Sort") == 0 && strcmp(this->get_name(),"pair_visitor") == 0)\
              {\
                  std::cout << s->get_name() << " can not applicalbe to " << this->get_name() << std::endl;\
                  return;\
              }\
              fisher_yates_shuffle();\
              std::cout << "*******" <<  s->get_name() << "*******";\
              std::cout<< "\nprior to run: " ;\
              this->print_array();\
              std::cout<<"+++++++++++++++++++++++++++" << std::endl;\
              s->init(a, sz);\
              s->do_work();\
              std::cout <<"post run: ";\
              this->print_array();\
              std::cout << "sorted? " << (this->isSorted() == false? "No": "Yes") << std::endl;\
              std::cout<<std::endl;\
              s->end();}
          

#define VISITOR_IMP(cl, T, C) \
          void cl::visit(bubble_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(heap_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(insert_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(quick_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(merge_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(radix_sort<T,C> *s)\
          VISITOR_BODY()

 #define VISITOR_IMP_P(cl, T, C) \
          void cl::visit(bubble_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(heap_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(insert_sort<T,C> *s)\
          VISITOR_BODY() \
          void cl::visit(quick_sort<T,C> *s)\
          VISITOR_BODY() \
          void  cl::visit(merge_sort<T,C> *s)\
          VISITOR_BODY() \

/*
          void cl::visit(radix_sort<T,C> *s)\
          VISITOR_BODY()
*/
#endif
