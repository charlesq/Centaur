#include <Singly_linked_list.hpp>
#include <iostream>
#include <functional>
int main()
{
    Singly_linked_list<int> sll;
    Singly_linked_list<int>::iterator it = sll.before_begin();
    it = sll.insert_after(it,6);
    it = sll.insert_after(it,5);
    it = sll.insert_after(it, 4); 
    it = sll.insert_after(it, 8);
    it = sll.insert_after(it, 10);
    it = sll.insert_after(it, 20);
    it = sll.insert_after(it, 2);

    sll.merge_sort(std::less<int>());
    it = sll.before_begin();
    std::cout << sll.front() << std::endl;
//    sll.erase_after(it);
    while(++it != sll.end())
     std::cout << *it << " " ;
    std::cout << std::endl;
    
    return 0;
}
