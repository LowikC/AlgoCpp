#include <gtest/gtest.h>
#include "EPI_19.5.hpp"

TEST(CycleTest, hasCycle) {
    UndirectedGraph g(4);
    g.insertEdge(0, 1);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(3, 1);

    CycleDetection cycle_det;
    ASSERT_TRUE(cycle_det.hasCycle(g));
}


TEST(CycleTest, hasNoCycle) {
    UndirectedGraph g(7);
    g.insertEdge(0, 1);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(2, 4);
    g.insertEdge(4, 5);
    g.insertEdge(1, 6);

    CycleDetection cycle_det;
    ASSERT_FALSE(cycle_det.hasCycle(g));
}
