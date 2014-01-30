#include "skip_list.hpp"
#include <iostream>

int main()
{
     skip_list<int, std::less<int>> slist;
     slist.insert(1);
     slist.insert(3);
     slist.insert(-1);
     slist.insert(5);
     if (!slist.search(-1))
     {
         std::cout << "search error!" << std::endl;
         return 0;
     }         
     
     return 0;
}
