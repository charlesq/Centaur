#ifndef __SINGLY_LINKED_LIST_HPP__
#define __SINGLY_LINKED_LIST_HPP__
#include <Node.hpp>
#include <stddef.h>
#include <stdint.h>
template <typename T>
class Singly_linked_list
{
    Node <T> head;
    size_t sz;

public:
     Singly_linked_list(void):sz(0) {};
     inline bool empty(void) const { return sz == 0;}; 
     inline size_t size(void) const { return sz; }; 
     virtual ~Singly_linked_list()
     {
         const Node <T> *n = head.get_next();
         const Node <T> *t = NULL;
         while(n != NULL)
         {
              t = n->get_next(); 
              delete n;
              n = t;
         }
     }; 
};

#endif
