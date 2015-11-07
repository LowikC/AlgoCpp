#include "gtest/gtest.h"
#include "Queue.hpp"

TEST(QueueTest, FIFOOrder) {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    ASSERT_EQ(queue.dequeue(), 1);
    ASSERT_EQ(queue.dequeue(), 2);
}

TEST(QueueTest, InitiallyEmpty) {
    Queue<int> queue;
    ASSERT_TRUE(queue.empty());
}
