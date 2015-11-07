#include "UndirectedGraph.hpp"

UndirectedGraph::UndirectedGraph(const int v) :
_adjacents(v),
_n_edges(0)
{};


int UndirectedGraph::E() const {
    return _n_edges;
}

int UndirectedGraph::V() const {
    return _adjacents.size();
}

const std::list<int>& UndirectedGraph::adj(int v) const {
    if (v < 0 || v > _adjacents.size()) throw std::range_error("Must be between 0 and V");
    return _adjacents[v];
}

void UndirectedGraph::insertEdge(int v, int w) {
    _adjacents[v].push_front(w);
    _adjacents[w].push_front(v);
}
