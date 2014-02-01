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
    action *discovered, *exploring, *explored;
    std::vector<unsigned int> colors;
    std::queue<unsigned int, std::deque<unsigned int>> q;/* vertices waited to be examined */ 
public:
    BFS(const graph &gh):g(gh)
    {
        discovered = exploring = explored = NULL;
    };
    void operator () (unsigned int v = 0)
    {
        unsigned int c = UNDISCOVERED;
        colors.clear();
        colors.resize(g.get_v(), c);
        colors[v] = DISCOVERED;
        if (discovered != NULL)
            discovered->act(v);
        q.push(v);
        run(); 
    };
    void set_discovered_action(action *a)
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
    void scan(unsigned int v)
    {
        if (exploring != NULL)
           exploring->act(v); 
        const forward_list<const edge *> &adj = g.get_adj(v); 
        int o;
        for (const edge *e: adj)
        {
            o = e->get_v() == v? e->get_o(): e->get_v();
            if (colors[o] == UNDISCOVERED)
            {
                colors[o] = DISCOVERED;
                if (discovered != NULL)
                    discovered->act(o);
                q.push(o);
            }
        }
        if (explored != NULL)
            explored->act(v);
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
