#ifndef __PRIM_H__
#define __PRIM_H__
#include "mst.hpp"
#include <vector>
#include <queue>
using namespace std;
class prim: public mst
{
    enum {UNDISCOVERED = 0, DISCOVERED, EXPLORED}; 
    vector<unsigned int> colors;
    priority_queue<const edge*, vector<const edge*>,  edge::compare_larger> pq; 
    void scan(unsigned int v)
    {
        if (colors[v] == DISCOVERED)
           return;
         colors[v] = DISCOVERED;
        const forward_list<const edge*> &adj = g.get_adj(v);
        unsigned int o;
        for (auto e: adj)
        {
           o = e->get_v() == v? e->get_o(): e->get_v(); 
           if (colors[o] == DISCOVERED)
              continue;
           pq.push(e);
        }
     
    };
public:
    prim(const graph &g):mst(g) {};
    forward_list<const edge *> operator () (unsigned int v = 0)
    {
#if 1 
       mstree.clear();
       unsigned int c = UNDISCOVERED;
       colors.resize(g.get_v(), c); 
       w = 0;
       unsigned int o;
       scan(v);
       const edge *e;
       while(!pq.empty())
       {
          e = pq.top(); 
          pq.pop();
          v = e->get_v();
          o = e->get_o();
          if (colors[v] == DISCOVERED && colors[o] == DISCOVERED)
              continue;
          mstree.push_front(e);
          scan(v);
          scan (o);
          w += e->get_w();
       }
       print_mst();
#endif
       return mstree;
       
    };
    virtual ~prim()
    {
        colors.clear();
    };
};

#endif
