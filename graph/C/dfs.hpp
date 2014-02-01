#ifndef __DFS_H__
#define __DFS_H__
#include <vector>
#include <forward_list>
#include "graph.hpp"
#include "action.hpp"
class DFS
{
    enum {UNDISCOVERED = 0, DISCOVERED, EXPLORED };
    const graph & g;
    action *discovered, *exploring, *explored;
    std::vector<unsigned int > colors; 
 public:
    DFS(const graph &gh): g(gh)
    {
        discovered = exploring = explored = 0;
    };
    void operator ()(unsigned int v = 0)
    {
        unsigned int c = UNDISCOVERED;
        colors.resize(0);
        colors.resize(g.get_v(), c);
        run(v);
    };
    void set_discovered_action(action * a)
    {
        discovered = a;
    };
    void set_explored_action(action *a)
    {
       explored = a;
    };
    void set_exploring_action(action *a)
    {
       exploring = a;
    };
private:
    void run(unsigned int v)
    {
        if (colors[v] != UNDISCOVERED)
            return;
        
        colors[v] = DISCOVERED; 
        if (discovered != NULL)
            discovered->act(v);
        if (exploring != NULL)
            exploring->act(v);
        const std::forward_list<const edge *> adj = g.get_adj(v);
        for (const edge *e: adj)
        {
            unsigned int o = e->get_v() == v? e->get_o(): e->get_v();
            run(o);
        }
        if (explored != NULL)
           explored->act(v); 
    };
public:
    virtual ~DFS()
    {
        colors.clear();
    };
    
};
 
#endif
