#ifndef __BFS_H__
#define __BFS_H__
#include <vector>
#include "action.hpp"
#include "graph.hpp"
#include <deque>
#include <queue>
class BFS
{
    enum {UNDISCOVERED = 0, DISCOVERED, EXPLORED};
    const graph &g;
    action act;
    std::vector<unsigned int> colors;
    std::queue<unsigned int, std::deque<unsigned int>> q;/* vertices waited to be examined */ 
public:
    BFS(const graph &gh):g(gh)
    {
    };
    void operator () (unsigned int v = 0)
    {
        unsigned int c = UNDISCOVERED;
        colors.clear();
        colors.resize(g.get_v(), c);
        colors[v] = DISCOVERED;
        act.act(v, "discovered ");
        q.push(v);
        run(); 
    };
private:
    void scan(unsigned int v)
    {
        act.act(v, " exploring "); 
        const forward_list<const edge *> &adj = g.get_adj(v); 
        int o;
        for (const edge *e: adj)
        {
            o = e->get_v() == v? e->get_o(): e->get_v();
            if (colors[o] == UNDISCOVERED)
            {
                colors[o] = DISCOVERED;
                act.act(o, "discovered ");
                q.push(o);
            }
        }
        act.act(v, "explored ");
    };
    void run(void)
    {
        unsigned int v;
        while(!q.empty())
        {
            v = q.front(); 
            q.pop();
            scan(v);
        }
    };
public:
    virtual ~BFS()
    {
        colors.clear();
    };
    
};

#endif
