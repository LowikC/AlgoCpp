#include "Queue.hpp"
#include <cassert>
#include <iostream>

int main(int argc, char** argv) {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    queue.enqueue(5);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    std::cout << queue.empty() << std::endl;

    return 1; // EXIT_SUCCESS;
}
