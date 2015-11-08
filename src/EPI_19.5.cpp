#include "EPI_19.5.hpp"


CycleDetection::CycleDetection() {

}

bool CycleDetection::hasCycle(const UndirectedGraph& g) {
    if(g.V() == 0) return false;

    _marked = std::deque<bool>(g.V(), false);
    bool has_cycle = dfs(g, 0, -1);
    return has_cycle;
}

bool CycleDetection::dfs(const UndirectedGraph& g, const int s, const int pred) {
    _marked[s] = true;
    for(auto v: g.adj(s)) {
        if(_marked[v] && v != pred) {
            return true;
        }
        if(!_marked[v]) {
            bool has_cycle = dfs(g, v, s);
            if(has_cycle) return true;
        }
    }
    return false;
}
