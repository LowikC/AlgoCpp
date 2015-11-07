#include "Stack.hpp"
#include <cassert>

int main(int argc, char** argv) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    assert(stack.pop() == 3);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);

    return EXIT_SUCCESS;
}
