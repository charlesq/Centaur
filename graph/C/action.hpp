#ifndef __ACTION_H__
#define __ACTION_H__
#include <iostream>
using namespace std;
class action
{
public:
   void act(unsigned int v, string msg) const
   {
       cout << msg << v << endl;
   };
};

#endif
