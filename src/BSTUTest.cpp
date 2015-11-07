#include "gtest/gtest.h"
#include "BST.hpp"
#include <set>
#include <algorithm>

TEST(BSTTest, insertContains) {
    BST bst;
    bst.insert(1);
    bst.insert(8);
    bst.insert(-4);

    ASSERT_TRUE(bst.contains(8));
    ASSERT_TRUE(bst.contains(-4));
    ASSERT_FALSE(bst.contains(0));

    ASSERT_EQ(bst.size(), 3);
}

TEST(BSTTest, minMax) {
    BST bst;
    bst.insert(1);
    bst.insert(8);
    bst.insert(-4);
    bst.insert(-5);
    bst.insert(13);
    bst.insert(-7);
    bst.insert(10);

    ASSERT_EQ(bst.min(), -7);
    ASSERT_EQ(bst.max(), 13);
}


TEST(BSTTest, floor) {
    BST bst;
    bst.insert(1);
    bst.insert(8);
    bst.insert(-4);
    bst.insert(-5);
    bst.insert(13);
    bst.insert(-7);
    bst.insert(10);

    ASSERT_EQ(bst.floor(11), 10);
    ASSERT_EQ(bst.floor(15), 13);
    ASSERT_EQ(bst.floor(-6), -7);
    ASSERT_EQ(bst.floor(-4), -4);
}


TEST(BSTTest, sort) {
    BST bst;
    bst.insert(1);
    bst.insert(8);
    bst.insert(-4);
    bst.insert(-5);
    bst.insert(13);
    bst.insert(-7);
    bst.insert(10);

    std::vector<int> sorted;
    bst.inOrder(sorted);

    for (size_t i = 0; i < sorted.size() - 1; i++) {
        ASSERT_TRUE(sorted[i] <= sorted[i + 1]);
    }
}


TEST(BSTTest, StdImplementation) {
    std::set<int> s({ 3, 5, -7, 8, 9, 1, -4 });

    std::vector<int> sorted;
    std::for_each(s.begin(), s.end(), [&sorted](int x) {sorted.push_back(x); });

    ASSERT_EQ(sorted.size(), s.size());
    ASSERT_TRUE(std::is_sorted(sorted.begin(), sorted.end()));
}