#ifndef __KOSARAJU_H__
#define __KOSARAJU_H__
#include <vector>
#include <forward_list>
#include "dfs.hpp"
#include <iostream>
/* print_action::act print discovered vertices into a sequence container */
class print_action: public action
{
    const graph &g;
    const std::vector<unsigned int > &colors;
    std::forward_list<unsigned int> scc;
public: 
    print_action(const graph &gh, const std::vector<unsigned int> &c):g(gh), colors(c)
    { };
    virtual void act(unsigned int v)
    {
        const std::forward_list<const edge *> &aj = g.get_adj(v); 
        for (const edge* e: aj)
        {
            if (colors[e->get_o()] == 0)
            {
                scc.push_front(v);
                return;
            }
        }
        scc.push_front(v);
        std::cout << "(" ; 
        while(!scc.empty())
        {
            std::cout << scc.front() << " ";
            scc.pop_front();
        }
        std::cout << ")" << std::endl;
    };
};
class store_sequence: public action
{
    std::forward_list<unsigned int> &seq;
public:
    store_sequence(std::forward_list<unsigned int> &s): seq(s) {};
    virtual void act(unsigned int v)
    {
        seq.push_front(v);
    };
};
class kosaraju
{
    const graph &g;
    const graph tg;
    std::forward_list<unsigned int> dfs_sequence;
public:
    kosaraju(const graph &gh): g(gh), tg(graph(g, true))
    { };
    void run()
    {
       /* run dfs on the original graph, output the dicovery sequence to the 
          forward list, dfs_sequence */
       DFS dfs(g);
       dfs.set_discovered_action(new store_sequence(dfs_sequence)); 
       for (unsigned int i = 0; i < g.get_v(); ++i)
           dfs.run(i); 
       /* transpose the graph and run dfs on it with vertices from the
          previously output sequence*/
       DFS dfst(tg);
       dfst.set_discovered_action(new print_action(tg, dfst.get_color())); 
       while(!dfs_sequence.empty())
       {
          dfst.run(dfs_sequence.front()); 
          dfs_sequence.pop_front();
       }
    };
};

#endif
