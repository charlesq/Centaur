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
         const Node<E> *node;
     public:
         Singly_linked_list_iterator(const Node<E> *n):node(n) {};
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
     iterator before_begin(void) const
     {
         return iterator(&head); 
     };
     iterator end(void) const
     {
         return iterator(last);
     };
     iterator insert_after(iterator pos, const T &v)
     {
         Node<T> *n = new Node<T>(v);
         n->set_next(pos.node->get_next());
         pos.node->set_next(n);
         return iterator(n);
     };
     iterator insert_after(iterator pos, T &&v)
     {
         Node<T> *n = new Node<T>(v);
         n->set_next(pos.node->get_next());
         pos.node->set_next(n);
         return iterator(n);
     };
     iterator erase_after(const iterator pos)
     {
         Node<T> *n = pos.node->get_next();
         pos.node->set_next(n->get_next());
         delete n;
         return iterator(pos.node->get_next());
      
     }; 
     void push_front(const T & v)
     {
         Node <T> *n = new Node<T>(v);
         n->set_next(head.node);
         head.set_next(n); 
     }; 
     void push_front(T && v)
     {
         Node <T> *n = new Node<T>(v);
         n->set_next(head.node);
         head.set_next(n);
     };
     /* bottom-up merge sort, break down the list into 2^i (i = 0, 1, 2 , ... )
       until 2^i >= size()
        merge every pair of consecutive sublists of length 2^(i-1) if necessary. 
      */

     template <typename Compare>
     void merge_sort(Compare cmp)
     {
         size_t _size = 1; 
         Node<T> *pre = &head, *middle;
         while (true)
         {
             size_t __first_seg_size  = _size, __second_seg_size ;
             while(pre != NULL && pre->get_next() != NULL &&  __first_seg_size --> 0)
                 middle = pre->get_next();
             __second_seg_size = _size - __first_seg_size;
             __first_seg_size = _size; 
            /* merge two consecutive subarrays */
             while(__first_seg_size != 0 && __second_seg_size != 0)
             {
                 if (cmp(middle->get_next()->value(), pre->get_next()->get_value()))
                 {
                     Node <T> *t = middle->get_next();
                     middle = t->get_next();
                     --__second_seg_size; 
                     t->set_next(pre->get_next());
                     pre->set_next(t);
                 }
                 else
                 {
                     --__first_seg_size;
                     pre = pre->get_next();
                 }
             }
             if(__first_seg_size != 0)
                 break; 
             while(__second_seg_size-- != 0)
                 middle = middle->get_next(); 
             pre = middle;
             if (pre != last)
                 continue;
             if (_size < size())
                 _size *= 2; 
             else
                 break;
         }
         
     };
     virtual ~Singly_linked_list()
     {
         clear();
         head.set_next(NULL);
     };
     void clear()  
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
