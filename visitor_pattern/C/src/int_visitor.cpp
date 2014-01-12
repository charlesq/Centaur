#include <inc/int_visitor.h>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <inc/macro.h>
int_visitor::int_visitor(size_t s)
{
   sz = s;
   a = new int[s]; 
   for (size_t i = 0; i < sz; ++i)
   {
       a[i] = i;
   }
}

int_visitor::~int_visitor(void)
{
    delete []a;
}

void int_visitor::print_element(const int &a) const
{
   std::cout<< a << " "; 
}
VISITOR_IMP(int_visitor, int, std::less<int>)
