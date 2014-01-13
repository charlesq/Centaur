#ifndef __VISITOR_H__
#define __VISITOR_H__
#include <iostream>
#include <cstddef>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>

template <typename T, typename C>
class bubble_sort;
template <typename T, typename C>
class heap_sort;
template <typename T, typename C>
class quick_sort;
template <typename T, typename C>
class  quick_sort;
template <typename T, typename C>
class merge_sort;
template <typename T, typename C>
class insert_sort;
template <typename T, typename C>
class radix_sort;

#define VISITOR_DECLARE(T, C) \
          virtual void  visit(bubble_sort<T,C> *s);\
          virtual void  visit(quick_sort<T,C> *s);\
          virtual void  visit(heap_sort<T,C> *s);\
          virtual void  visit(radix_sort<T,C> *s);\
          virtual void  visit(merge_sort<T,C> *s);\
          virtual void  visit(insert_sort<T,C> *s);
#define VISITOR_DECLARE_P(T, C) \
          virtual void  visit(bubble_sort<T,C> *s);\
          virtual void  visit(quick_sort<T,C> *s);\
          virtual void  visit(heap_sort<T,C> *s);\
          virtual void  visit(merge_sort<T,C> *s);\
          virtual void  visit(insert_sort<T,C> *s);

template<typename T, typename C> 
class visitor
{
protected:
    T *a;
    size_t sz;
    /* a common method to shuffle array elements */
    virtual void fisher_yates_shuffle(void) final
    {
        for (size_t i = 1; i < sz; ++i)
        {
            size_t j = rand() % ( i + 1);
            std::swap<T>(a[i], a[j]);
        }

    };
    virtual void print_element(const T &)  const =0;
public:
    virtual const char *get_name(void) const =0;
    visitor(void):a(NULL), sz(0)
    {
        srand(time(NULL));
    }; 
    bool isSorted(void)const
    {
        C c;
        for (size_t i = 0; i +1 < sz; ++i)
        {
           if (c(a[i+1],a[i]))
              return false;
        }
        return true;
    }
    virtual void print_array(void) final
    {
       #define COUNT 10
       for (size_t i = 0; i < sz; ++i)
       {
           if (i % 10 == 0)
               std::cout << std::endl;
           print_element(a[i]);
           
       }
       std::cout << std::endl;
    };
    virtual void visit(bubble_sort<T,C> *) {};
    virtual void visit(insert_sort<T,C> *) {};
    virtual void visit(quick_sort<T,C> *) {};
    virtual void visit(merge_sort<T,C> *) {};
    virtual void visit(heap_sort<T,C> *) {};
    virtual void visit(radix_sort<T,C> *) {} ;
    virtual ~visitor()
    {
    };
};
#endif
