#include "Stack.h"

#include <cassert>

template <typename T>
Stack<T>::Stack(size_t cap) : buff_(allocate(cap)), cap_(cap), top_(0) {}

template <typename T>
void Stack<T>::push(const T &val) {
    if (top_ == cap_) {
        auto new_buff = allocate(grow_coefficient * cap_);
        for (size_t i = 0; i < top_; ++i) {
            new_buff[i] = buff_[i];
        }
        deallocate(buff_);
        buff_ = new_buff;
        cap_ *= grow_coefficient;
    }

    buff_[top_++] = val;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &another) {
    deepCopy (another);    
}

template <typename T>
Stack<T>::Stack(Stack<T> &&another) {
    lightCopy (another);
    another.cleanUp();
}

template <typename T>
void Stack<T>::deepCopy (const Stack<T> &another) {
    buff_ = allocate (another.top_);
    cap_  = another.top_;
    for (size_t i = 0; i < cap_; ++i) {
        push (another.buff_[i]);
    }
}

template <typename T>
void Stack<T>::lightCopy (const Stack<T> &another) {
    buff_ = another.buff_;
    cap_  = another.cap_;
    top_ = another.top_;
}

template <typename T>
Stack<T> &Stack<T>::operator = (Stack<T> &another) {
    this->~Stack();
    this->deepCopy (another);

    return *this;
}

template <typename T>
void Stack<T>::pop() {
    assert(top_ != 0 && "Popping empty stack");
    buff_[--top_].~T();
}

template <typename T>
const T &Stack<T>::top() const {
    assert(top_ != 0);
    return buff_[top_ - 1];
}

template <typename T>
T &Stack<T>::top() {
    assert(top_ != 0);
    return buff_[top_ - 1];
}

template <typename T>
Stack<T>::~Stack<T>() {
    deallocate(buff_);
    cleanUp();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top_ == 0;
}

template <typename T>
T *Stack<T>::allocate(size_t n) const {
    return new T[n];
}

template <typename T>
void Stack<T>::deallocate(T *data) const {
    delete[] data;
}

template <typename T>
void Stack<T>::cleanUp() {
    buff_ = nullptr;
    cap_ = 0;
    top_ = 0;
}