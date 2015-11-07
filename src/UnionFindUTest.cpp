#include "gtest/gtest.h"
#include "UnionFind.hpp"

TEST(UnionFindTest, groupTwoElements) {
    UnionFind uf(10);
    uf.union_(0, 1);
    ASSERT_TRUE(uf.connected(0, 1));
}

TEST(UnionFindTest, initiallyNoConnected) {
    UnionFind uf(3);
    ASSERT_FALSE(uf.connected(0, 1));
    ASSERT_FALSE(uf.connected(0, 2));
    ASSERT_FALSE(uf.connected(1, 2));
}

TEST(UnionFindTest, groupSeveralElements) {
    UnionFind uf(10);
    uf.union_(0, 9);
    uf.union_(0, 8);
    uf.union_(1, 7);
    uf.union_(1, 6);
    ASSERT_FALSE(uf.connected(0, 1));

    uf.union_(6, 5);
    uf.union_(8, 5);

    ASSERT_TRUE(uf.connected(0, 1));
    ASSERT_EQ(uf.count(), 4);
}