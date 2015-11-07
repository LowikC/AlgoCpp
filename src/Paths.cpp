#include "Paths.hpp"


Paths::Paths(const UndirectedGraph& g, const int src):
_marked(g.V(), false),
_from(g.V()) 
{
    for (size_t i = 0; i < _from.size(); i++) {
        _from[i] = i;
    }

    dfs(g, src);
}

void Paths::dfs(const UndirectedGraph& g, const int src) {
    _marked[src] = true;
    for (auto v : g.adj(src)) {
        if (!_marked[v]) {
            _from[v] = src;
            dfs(g, v);
        }
    }
}

bool Paths::hasPathTo(const int v) {
    return _marked[v];
}

std::list<int> Paths::pathTo(const int v) {
    std::list<int> path;
    if (!hasPathTo(v)) return path;

    int current = v;
    while (_from[current] != current) {
        path.push_front(current);
        current = _from[current];
    }
    path.push_front(current);
    return path;
}
