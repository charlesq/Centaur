#ifndef __EDGE_H__
#define __EDGE_H__
#include <iostream>
using namespace std;
class edge
{
    const unsigned int v; /* for directional edge, this is the from vertex */
    const unsigned int other; /* for directional edge, this is the to vertex */
    const int w;
 public:
     edge (unsigned int v1, unsigned int v2, int wt) : v(v1), other(v2), w(wt) {};
     inline unsigned int get_v(void) const { return v; };
     inline unsigned int get_o(void) const { return other; };
     inline unsigned int get_w(void) const { return w; };
     static void print_edge(const edge *e)
     {
         cout << "(" << e->v << "," << e->other << "," << e->w <<  ") ";
     };
    class compare
    {
    public:
        bool operator ()(const edge *e1, const edge *e2) const
        {
            return e1->w < e2->w;
        };
    };
    class compare_larger
    {
    public:
        bool operator() (const edge *e1, const edge *e2) const
        {
            return e2->w < e1->w;
        };
    };
 
     virtual ~edge () {};
};
#endif
