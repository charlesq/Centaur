#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <forward_list>
#include <vector>
#include <iostream>
#include <fstream>
#include "edge.hpp"
using namespace std;
class graph
{
   unsigned int V; /* total number of vertices in the graph
                            vertices are numbered from 0 to V-1 */
   vector<forward_list<const edge *>> adj; /* linked lists to represent adjancy */
   forward_list<const edge *> edges; /* stores all edges in the graph */ 
public:
   graph(string fn, bool directed = false)/* graph topology stores in a file */
   {
       ifstream ism(fn); 
       if (!ism.is_open())
       {
          V = 0;
          cout << "failed to opne configuration file ! " << endl; 
          return;
       }
       /* obtain V and number of edges */ 
       unsigned int en, v1, v2, w;
       edge *lnk;
       ism >> V >> en;
       /* set adj size */
       adj.resize(V);
       while (en -- != 0)
       {
           ism >> v1 >> v2 >> w; 
           lnk = new edge(v1, v2, w); 
           edges. push_front(lnk);
           adj[v1].push_front(lnk);
           if (!directed)
              adj[v2].push_front(lnk);
          
       }
       ism.close();
   };
   inline unsigned int get_v(void) const { return V; };
   inline const forward_list<const edge *> & get_adj(unsigned int v) const { return adj[v]; }; 
   inline const forward_list<const edge *> & get_edges(void) const { return edges; };
   ~graph()
   {
       for (forward_list<const edge *> & l: adj)
           l.clear();
       adj.clear();
       for (const edge * e: edges)
           delete e;
       edges.clear();
   };
    
};

#endif
