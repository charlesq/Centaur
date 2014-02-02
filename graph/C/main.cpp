#include "dfs.hpp"
#include "bfs.hpp"
#include "disjointed_set.hpp"
#include "mst.hpp"
#include "kruskal.hpp"
#include "prim.hpp"
#include "kosaraju.hpp"
int main()
{
    graph g("graph.txt");
    DFS dfs(g);
    BFS bfs(g);
    dfs.set_discovered_action(new default_discovered());
    dfs.set_exploring_action(new default_exploring());
    dfs.set_explored_action(new default_explored());
    bfs.set_discovered_action(new default_discovered());
    bfs.set_exploring_action(new default_exploring());
    bfs.set_explored_action(new default_explored());
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
    graph gh("graph.txt", true);
    kosaraju ko(gh);
    ko.run();
    return 0;
}
