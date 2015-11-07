#include "gtest/gtest.h"
#include "MaxPriorityQueue.hpp"
#include <queue>

TEST(MaxPriorityQueueTest, initiallyEmpty) {
    MaxPriorityQueue<int> max_pq;
    ASSERT_TRUE(max_pq.empty());
}

TEST(MaxPriorityQueueTest, CheckMaxOne) {
    MaxPriorityQueue<int> max_pq;
    max_pq.insert(1);
    max_pq.insert(3);
    max_pq.insert(2);
    ASSERT_EQ(max_pq.max(), 3);
}

TEST(MaxPriorityQueueTest, PopMaxStatic) {
    MaxPriorityQueue<int> max_pq;
    max_pq.insert(1);
    max_pq.insert(3);
    max_pq.insert(4);
    max_pq.insert(2);
    ASSERT_EQ(max_pq.popMax(), 4);
    ASSERT_EQ(max_pq.popMax(), 3);
    ASSERT_EQ(max_pq.popMax(), 2);
    ASSERT_EQ(max_pq.popMax(), 1);
    ASSERT_TRUE(max_pq.empty());
}

TEST(MaxPriorityQueueTest, PopMaxDynamic) {
    MaxPriorityQueue<int> max_pq;
    max_pq.insert(1);
    max_pq.insert(3);
    max_pq.insert(2);
    ASSERT_EQ(max_pq.popMax(), 3);
    max_pq.insert(4);
    max_pq.insert(5);

    ASSERT_EQ(max_pq.popMax(), 5);
    ASSERT_EQ(max_pq.popMax(), 4);
    ASSERT_EQ(max_pq.popMax(), 2);
    ASSERT_FALSE(max_pq.empty());
}

TEST(MaxPriorityQueueTest, StandardImplementation) {
    struct MinCompator {
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    std::priority_queue<int, std::vector<int>, MinCompator> min_pq;

    min_pq.push(2);
    min_pq.push(1);
    min_pq.push(3);
    ASSERT_EQ(min_pq.top(), 1);
    min_pq.pop();
    min_pq.push(0);
    min_pq.push(-1);

    ASSERT_EQ(min_pq.top(), -1);
    min_pq.pop();
    ASSERT_EQ(min_pq.top(), 0);
    min_pq.pop();
    ASSERT_EQ(min_pq.top(), 2);
    min_pq.pop();
    ASSERT_FALSE(min_pq.empty());
}
