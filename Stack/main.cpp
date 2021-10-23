#include <iostream>

#include "StackLib/Stack_impl.hpp"

#include <gtest/gtest.h>

const size_t n_iter = 128;

int main() {
    Stack<int> stk;
    Stack<bool> stk_spec;

    for (size_t i = 0; i < n_iter; ++i) {
        stk.push(i);
    }

    std::cout << "dump:" << std::endl;
    while (!stk.isEmpty()) {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }

    for (size_t i = 0; i < n_iter; ++i) {
        stk_spec.push(i % 3 == 0);
    }

    std::cout << "spec dump:" << std::endl;
    while (!stk_spec.isEmpty()) {
        std::cout << stk_spec.top() << std::endl;
        stk_spec.pop();
    }
}