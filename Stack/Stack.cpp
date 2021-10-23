#include "Stack.h"

#include <cassert>
#include <climits>
#include <cstdlib>

inline size_t to_bytes(size_t nbits) {
    return nbits / CHAR_BIT + (nbits % CHAR_BIT) ? 1 : 0;
}

inline bool get_bit(const byte_t *arr, size_t idx) {
    return (arr[idx / CHAR_BIT] >> (idx % CHAR_BIT)) & 1u;
}

inline void set_bit(byte_t *arr, size_t idx, bool val) {
    if (val)
        arr[idx / CHAR_BIT] |= (1u << (idx % CHAR_BIT));
    else
        arr[idx / CHAR_BIT] &= ~(1u << (idx % CHAR_BIT));
}

byte_t *Stack<bool>::allocate(size_t nbits) const {
    return new byte_t[to_bytes(nbits)];
}

void Stack<bool>::deallocate(byte_t *data) const { delete[] data; }

Stack<bool>::Stack(size_t cap) : buff_(allocate(cap)), cap_(cap), top_(0) {}

void Stack<bool>::push(bool val) {
    if (top_ == cap_) {
        auto new_buff = allocate(grow_coefficient * cap_);
        for (size_t i = 0; i < top_; ++i) {
            new_buff[i] = buff_[i];
        }
        deallocate(buff_);
        buff_ = new_buff;
        cap_ *= grow_coefficient;
    }

    set_bit(buff_, top_++, val);
}

void Stack<bool>::pop() {
    assert(top_ != 0 && "Popping empty stack");
    set_bit(buff_, --top_, false);
}

bool Stack<bool>::top() const {
    assert(top_ != 0);
    return get_bit(buff_, top_ - 1); 
}

Stack<bool>::~Stack<bool>() {
    deallocate(buff_);
    buff_ = nullptr;
    cap_ = 0;
    top_ = 0;
}

bool Stack<bool>::isEmpty() const { return top_ == 0; }