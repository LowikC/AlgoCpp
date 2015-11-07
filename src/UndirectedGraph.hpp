#ifndef undirected_graph_hpp
#define undirected_graph_hpp

#include <list>
#include <vector>

class UndirectedGraph {
public:
    UndirectedGraph(const int e);

    int E() const;
    
    int V() const;

    void insertEdge(int v, int w);

    const std::list<int>& adj(int v) const;

private:
    std::vector<std::list<int>> _adjacents;
    size_t _n_edges;
};

#endif