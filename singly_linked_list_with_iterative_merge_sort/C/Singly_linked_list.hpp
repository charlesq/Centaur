#ifndef __SINGLY_LINKED_LIST_HPP__
#define __SINGLY_LINKED_LIST_HPP__
#include <Node.hpp>
#include <stddef.h>
#include <stdint.h>
template <typename T>
class Singly_linked_list
{
    Node <T> head;
    Node <T> *last;
    size_t sz;

public:
     template <typename E>
     class Singly_linked_list_iterator 
     {
         Node<E> *node;
     public:
         Singly_linked_list_iterator(Node<E> *n):node(n) {};
         Singly_linked_list_iterator (const Singly_linked_list_iterator & it) :node(it.node){};
         T  operator * (void) const
         {
  
             return node->get_value();
         };
         inline Singly_linked_list_iterator & operator ++ ()
         {
             node = node.get_next();
             return *this;
         };
         inline Singly_linked_list_iterator operator ++ (int)
         {
             Singly_linked_list_iterator ret = *this;
             node = node.get_next();
             return ret;
         };
         inline bool operator == (const Singly_linked_list_iterator &a) const
         {
             return a.node == this->node;
         };
         inline bool operator != (const Singly_linked_list_iterator &a) const
         {
             return a.node != this->node;
         };
         T  &operator -> (void) const
         {
             return node->get_value();
         }; 
         private: 
            friend class Singly_linked_list<E>;
     
     };
     typedef Singly_linked_list_iterator<T> iterator;
     Singly_linked_list(void):sz(0),last(&head) {};
     inline bool empty(void) const { return sz == 0;}; 
     inline size_t size(void) const { return sz; }; 
     iterator begin(void) const
     {
         return iterator(&head); 
     };
     iterator end(void) const
     {
         return iterator(last);
     };
     iterator insertAfter(iterator pos, T &v)
     {
         Node<T> *n = new Node<T>(v);
         n->set_next(pos.node->get_next());
         pos.node->set_next(n);
         return iterator(n);
     }; 
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
