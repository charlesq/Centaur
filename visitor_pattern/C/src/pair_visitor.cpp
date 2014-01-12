#include <inc/pair_visitor.h>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <functional>
#include <algorithm>
#include <inc/macro.h>


pair_visitor::pair_visitor(size_t s)
{
    sz = s;
    a = new paired[sz]; 
    for (size_t i = 0; i < sz; ++i)
    {
        a[i].first = i;
        a[i].second = rand() % 311;
    }
}

pair_visitor::~pair_visitor()
{
   delete [] a;
}
void pair_visitor::print_element(const paired &a) const
{
    std::cout <<  "(" << a.first << "," << a.second << ") ";
}

VISITOR_IMP(pair_visitor, paired, paired_compare)
