#ifndef __ACTION_H__
#define __ACTION_H__
#include <iostream>
using namespace std;
class action
{
public:
   virtual void act(unsigned int v) const = 0;
};

class default_discovered: public action
{
public:
    virtual void act(unsigned int v) const
    {
        cout << "discovered " << v << endl;
    };
};
class default_exploring: public action
{
public:
    virtual void act(unsigned int v) const
    {
        cout << "explring " << v << endl;
    };
};
class default_explored: public action
{
public:
    virtual void act(unsigned int v) const
    {
        cout << "explored " << v << endl;
    }; 
};
#endif
