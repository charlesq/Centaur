#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__
#include "disjointed_set.hpp"
#include <vector>
#include <cstddef>
#include <algorithm>
#include <forward_list>
#include  "mst.hpp"
using namespace std;
class compare;
class kruskal: public mst
{
     vector<disjointed_set *> ds; 
public:
     kruskal(const graph & gh):mst(gh)
     {
     };
     virtual forward_list<const edge *> operator () (unsigned int v)
     {
        mstree.clear();
        ds.clear();
        ds.resize(g.get_v());
        w = 0;
        /* make a set for each vertex in the graph */
        for (size_t i = 0; i < g.get_v(); ++i)
        {
            ds[i] = make_set(i);
        }
        /* sort all the edges */
        forward_list<const edge *> edges = g.get_edges();
        /* we may use a priority queue as well*/
        edges.sort(edge::compare()); 
        unsigned int v1, v2;
        for (forward_list<const edge *>::iterator it = edges.begin(); it != edges.end(); ++it)
        {
            v1 = (*it)->get_v();
            v2 = (*it)->get_o(); 
            if (find_set(ds[v1]) == find_set(ds[v2]))
                continue;
            mstree.push_front(*it);
            make_union(ds[v1], ds[v2]);
            w += (*it)->get_w();
        }
        print_mst();
        return mstree;
  
     };
};
#endif
