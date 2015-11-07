#include "gtest/gtest.h"
#include "Paths.hpp"

TEST(PathsTest, reachability) {
    UndirectedGraph g(6);
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);

    g.insertEdge(4, 5);

    Paths path(g, 0);

    ASSERT_TRUE(path.hasPathTo(1));
    ASSERT_TRUE(path.hasPathTo(2));
    ASSERT_TRUE(path.hasPathTo(3));

    ASSERT_FALSE(path.hasPathTo(4));
    ASSERT_FALSE(path.hasPathTo(5));
}

TEST(PathsTest, pathTo) {
    UndirectedGraph g(6);
    g.insertEdge(0, 1);
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(4, 5);

    Paths path(g, 0);

    ASSERT_TRUE(path.hasPathTo(2));

    auto pathTo2 = path.pathTo(2);
    ASSERT_TRUE(std::find(pathTo2.begin(), pathTo2.end(), 0) != pathTo2.end());
    ASSERT_TRUE(std::find(pathTo2.begin(), pathTo2.end(), 1) != pathTo2.end() || std::find(pathTo2.begin(), pathTo2.end(), 3) != pathTo2.end());
    ASSERT_TRUE(std::find(pathTo2.begin(), pathTo2.end(), 2) != pathTo2.end());
    ASSERT_TRUE(pathTo2.front() == 0);
    ASSERT_TRUE(pathTo2.back() == 2);
    ASSERT_TRUE(pathTo2.size() == 3);
}