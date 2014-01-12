#ifndef __PAIR_VISITOR_H__
#define __PAIR_VISITOR_H__
#include <cstdint>
#include <functional>
#include <inc/visitor.h>
#include <utility>
using namespace std;
typedef  pair<int, int> paired;

class paired_compare
{
public:
    bool operator()(const paired &a, const paired &b) const
    {
        return a.first < b.first;
    };
};

class pair_visitor:public visitor<paired ,paired_compare>
{
    paired *a;
    size_t sz;
    void print_element(const paired &) const;
public:
    pair_visitor(size_t s);
    const char *get_name(void) const { return "pair_visitor"; };
    virtual ~pair_visitor();
    VISITOR_DECLARE(paired, paired_compare)
};

#endif
