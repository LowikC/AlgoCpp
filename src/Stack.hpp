#ifndef stack_hpp
#define stack_hpp

#include <vector>

template <typename T>
class Stack {
  
public:
    Stack();
    void push(const T& item);
    T pop();
    bool empty();

 private:
    std::vector<T> _stack;
};

#include "Stack.tpp"

#endif //#ifndef stack_hpp
