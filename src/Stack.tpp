#include <exception>

template <typename T>
Stack<T>::Stack() {}

template <typename T>  
void Stack<T>::push(const T& item) {
    _stack.push_back(item);
}

template <typename T>
T Stack<T>::pop() {
    if (_stack.empty()) {
        throw std::overflow_error("Empty stack");
    }
    T back = _stack.back();
    _stack.pop_back();
    return back;
}

template <typename T>
bool Stack<T>::empty() {
    return _stack.empty();
}

