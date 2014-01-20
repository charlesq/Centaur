#ifndef __NODE_HPP__
#define __NODE_HPP_
#include <stddef.h>
template <typename T>
class Node
{
    T value;
    Node *nxt; 
public:
    Node (void):nxt(NULL){};
    Node(T &&v):value(v), nxt(NULL)
    {
    };
    Node (T &v):value(v), nxt (NULL) {};
    Node (T &&v, Node<T> *n):value(v), nxt(n)
    {
    };
    Node (T &v, Node<T> *n):value(v), nxt(n) {};
    inline T &get_value(void) const
    {  
        return value;
    };
    inline T get_value(void)
    {
        return value;
    };
    inline void set_next(Node<T> *n)
    {
        nxt = n;
    };
    inline const Node<T>* get_next(void) const
    {
        return nxt;
    };
   
    virtual ~Node()
    {
    }; 
};
#endif
