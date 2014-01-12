#ifndef __ACCEPT_IF_H__
#define __ACCEPT_IF_H__
template <typename T, typename C>
class visitor;
/* this defines  accept interface */
template <typename T, typename C>
class accept_if
{
public:
   virtual void accept(visitor<T,C> *v) = 0; 
};
#endif
