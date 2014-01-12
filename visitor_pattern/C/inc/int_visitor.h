#ifndef __INT_VISITOR_H__
#define __INT_VISITOR_H__
#include <cstdint>
#include <functional>
#include <inc/visitor.h>

class int_visitor:public visitor<int, std::less<int>>
{
    int *a;
    size_t sz;
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
