#ifndef Queue_hpp
#define Queue_hpp

#include <stdexcept>
#include <cassert>

template <typename T>
struct ListNode {
    T value;
    ListNode* next;

    ListNode(const T& value, ListNode* next = nullptr) :
    value(value),
    next(next)
    {}
};

template <typename T>
class Queue {
public:
    Queue();

    void enqueue(const T& value);

    T dequeue();

    bool empty();

private:
    ListNode<T>* head;
    ListNode<T>* last;
    size_t size;
};

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    last = nullptr;
    size = 0;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    ListNode<T>* node = new ListNode<T>(value);
    if (head == nullptr) {
        head = node;
        last = node;
    }
    else {
        assert(last != nullptr);
        last->next = node;
        last = last->next;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (size == 0) {
        throw std::underflow_error("Empty queue");
    }
    assert(head != nullptr);
    assert(last != nullptr);

    // Remove the head of the list.
    ListNode<T>* old_node = head;
    head = head->next;
    size--;

    if (head == nullptr) last = nullptr;

    T value = old_node->value;
    delete old_node;
    return value;
}

template <typename T>
bool Queue<T>::empty() {
    return size == 0;
}

#endif