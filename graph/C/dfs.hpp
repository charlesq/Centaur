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
    action act;
    std::vector<unsigned int > colors; 
 public:
    DFS(const graph &gh): g(gh)
    {
    };
    void operator ()(unsigned int v = 0)
    {
        unsigned int c = UNDISCOVERED;
        colors.resize(0);
        colors.resize(g.get_v(), c);
        run(v);
    };
private:
    void run(unsigned int v)
    {
        if (colors[v] != UNDISCOVERED)
            return;
        
        colors[v] = DISCOVERED; 
        act.act(v, "discovered ");
        act.act(v, "  exploring ");
        const std::forward_list<const edge *> adj = g.get_adj(v);
        for (const edge *e: adj)
        {
            unsigned int o = e->get_v() == v? e->get_o(): e->get_v();
            run(o);
        }
        act.act(v, "explored "); 
    };
public:
    virtual ~DFS()
    {
        colors.clear();
    };
    
};
 
#endif
