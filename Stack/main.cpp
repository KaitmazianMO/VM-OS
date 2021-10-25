#include <unistd.h>

#include <cstdio>
#include <iostream>
#include <utility>

#include "StackLib/Stack_impl.hpp"

const size_t n_iter = 128;

int main() {
    std::cout << "nbits / CHAR_BIT + (nbits % CHAR_BIT) ? 1 : 0 = "
              << (32 / 8 + (32 % 8) ? 1 : 0) << std::endl;

    Stack<int> stk;
    Stack<bool> stk_spec;
    auto stk_to_copy = stk;
    auto stk_to_move = std::move(stk);
    stk_to_copy = stk_to_move;
    Stack<bool> copy = stk_spec;
    copy = stk_spec;

    // for (size_t i = 0; i < n_iter; ++i) {
    //    stk.push(i);
    //}

    // std::cout << "dump:" << std::endl;
    // while (!stk.isEmpty()) {
    //    std::cout << stk.top() << std::endl;
    //    stk.pop();
    //}

    std::cout << "Run action" << std::endl;

    //for (size_t i = 0; i < n_iter; ++i) {
    //    stk_spec.push(i % 3 == 0);
    //}

    std::cout << "spec dump:" << std::endl;
    while (!stk_spec.isEmpty()) {
        std::cout << stk_spec.top() << std::endl;
        stk_spec.pop();
    }

    std::cout << "End action" << std::endl;
    return 0;
}