#ifndef __MST_H__
#define __MST_H__
#include <forward_list>
#include "graph.hpp"
#include <iostream>
class mst
{

protected:
    const graph &g;
    std::forward_list<const edge *> mstree;
    unsigned int w;
public:
    mst(const graph &gh):g(gh) {};
    virtual std::forward_list<const edge *> operator()(unsigned int v = 0)=0;
    virtual ~mst()
    {
    };
    virtual void print_mst(void) const
    {
        std::cout << "mst consists of following edges :\n";
        for (auto e: mstree)
            edge::print_edge(e);
        std::cout << std::endl << "total weight of edges in mst is " << w << std::endl;
        
    };
};

#endif

