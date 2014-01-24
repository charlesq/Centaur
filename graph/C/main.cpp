#include "dfs.hpp"
#include "bfs.hpp"
#include "disjointed_set.hpp"
#include "mst.hpp"
#include "kruskal.hpp"
#include "prim.hpp"
int main()
{
    graph g("graph.txt");
    DFS dfs(g);
    BFS bfs(g);
    std::cout << "running depth first search " << std::endl;
    dfs(0);
    std::cout << "running breadth first search " << std::endl;
    bfs(0); 
    std::cout << "running kruskal algorithm " << std::endl;
    mst *kal = new kruskal(g);
    (*kal)();
    delete kal;
    std::cout << "running prim algorithm " << std::endl;
    mst *pral = new prim(g);
    (*pral)();
    delete pral;
    return 0;
}
