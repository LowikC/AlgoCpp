#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp

#include <vector>
#include <algorithm>

template <typename Key>
class MaxPriorityQueue {
public:
    //! Build a MaxPQ with some initials values.
    //! By default, the PQ will be empty.
    MaxPriorityQueue(std::vector<Key>& initials = std::vector<Key>());

    //! Insert a Key
    void insert(const Key& T);

    //! Return the maximum key.
    Key max() const;

    //! Return and delete the maximum key.
    Key popMax();

    //! Check if the PQ is empty.
    bool empty() const;

private:
    std::vector<Key> _queue;
};

template <typename Key>
MaxPriorityQueue<Key>::MaxPriorityQueue(std::vector<Key>& initials) :
_queue(initials) {
    std::make_heap(_queue.begin(), _queue.end());
}

template <typename Key>
void MaxPriorityQueue<Key>::insert(const Key& x) {
    _queue.push_back(x);
    std::push_heap(_queue.begin(), _queue.end());
}

template <typename Key>
Key MaxPriorityQueue<Key>::popMax() {
    if (_queue.empty()) {
        throw std::underflow_error("Empty Queue");
    }
    std::pop_heap(_queue.begin(), _queue.end());
    Key value = _queue.back();
    _queue.pop_back();
    return value;
}

template <typename Key>
Key MaxPriorityQueue<Key>::max() const{
    if (_queue.empty()) {
        throw std::underflow_error("Empty Queue");
    }
    return _queue.front();
}

template <typename Key>
bool MaxPriorityQueue<Key>::empty() const{
    return _queue.empty();
}

#endif