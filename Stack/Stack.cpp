#include "Stack.h"
#include <cassert>
#include <cstdlib>
#include <climits>

constexpr size_t bool_nbits = sizeof (bool) * CHAR_BIT;
static inline size_t to_bytes (size_t nbits) {
    return nbits / bool_nbits + (nbits % bool_nbits) ? 1 : 0;
}

bool get_bit (const bool *arr, size_t idx) {
    return (arr[idx/bool_nbits] >> (idx%bool_nbits)) & 1u;
}

void set_bit (bool *arr, size_t idx, bool val) {
    if (val)
        arr[idx/bool_nbits] |= (1u << (idx%bool_nbits));
    else
        arr[idx/bool_nbits] &= ~(1u << (idx%bool_nbits));            
}


#include <iostream>
template <>
Stack<bool>::Stack(size_t cap) : buff_(allocate(cap)), cap_(cap), top_(0) {
    std::cout << "Called spec bool template" << std::endl;
}

template <>
void Stack<bool>::push(const bool &val) {
    if (top_ == cap_) {
        auto new_buff = allocate(grow_coefficient * cap_);
        for (size_t i = 0; i < top_; ++i) { 
            new_buff[i] = buff_[i];
        }
        deallocate(buff_);
        buff_ = new_buff;
        cap_ *= grow_coefficient;
    }

    set_bit (buff_, top_++, val);
    //buff_[top_++] = val;
}

template <>
void Stack<bool>::pop() {
    assert(top_ != 0 && "Popping empty stack");
    set_bit (buff_, --top_, false);
    //buff_[--top_] = false;
}

template <>
const bool &Stack<bool>::top() const {
    assert(top_ != 0);
    return get_bit (buff_, top_ - 1);/*buff_[top_ - 1];*/
}

template <>
Stack<bool>::~Stack<bool>() {
    deallocate(buff_);
    buff_ = nullptr;
    cap_ = 0;
    top_ = 0;
}

template <>
bool Stack<bool>::isEmpty() const {
    return top_ == 0;
}

template <>
bool *Stack<bool>::allocate(size_t nbits) const {
    return new bool[to_bytes (nbits)];
}

template <>
void Stack<bool>::deallocate(bool *data) const {
    delete[] data;
}
