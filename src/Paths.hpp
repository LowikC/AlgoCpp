#ifndef paths_hpp
#define paths_hpp

#include <deque>
#include "UndirectedGraph.hpp"

class Paths {
public:
    Paths(const UndirectedGraph& g, const int src);

    bool hasPathTo(const int v);

    std::list<int> pathTo(const int v);

private:
    void dfs(const UndirectedGraph& g, const int src);

    std::deque<bool> _marked;
    std::vector<int> _from;
};

#endif 