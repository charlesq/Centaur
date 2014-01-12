#ifndef __INT_VISITOR_H__
#define __INT_VISITOR_H__
#include <cstdint>
#include <functional>
#include <inc/visitor.h>
#include <inc/macro.h>
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

class int_visitor:public visitor<int, std::less<int>>
{
    void print_element(const int &a) const;
public:
    int_visitor(size_t s);
    virtual ~int_visitor();
    const char *get_name(void) const
    {
        return "int_visitor";
    };
    VISITOR_DECLARE(int, std::less<int>)
};
#endif
