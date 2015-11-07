#include "gtest/gtest.h"
#include "Stack.hpp"

TEST(StackTest, LIFOOrder) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.pop(), 3);
    ASSERT_EQ(stack.pop(), 2);
}
