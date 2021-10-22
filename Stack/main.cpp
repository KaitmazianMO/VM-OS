#include <iostream>

#include "Stack.cpp"

const size_t n_iter = 128;

int main() {
  Stack<int> stk;

  for (size_t i = 0; i < n_iter; ++i) {
    stk.push(i);
  }

  std::cout << "dump:" << std::endl;
  while (!stk.isEmpty()) {
    std::cout << stk.top() << std::endl;
    stk.pop();
  }
}