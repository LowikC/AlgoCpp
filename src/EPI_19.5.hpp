#ifndef epi_19_5_hpp
#define epi_19_5_hpp

//! This is a solution to exercise 19.5 in Elements of Programming Interviews.
#include "UndirectedGraph.hpp"
#include <deque>

class CycleDetection {
public:
    CycleDetection();

    bool hasCycle(const UndirectedGraph& g);

private:
    bool dfs(const UndirectedGraph& g, const int s, const int pred);
    std::deque<bool> _marked;
};

#endif
