#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <cstdlib>
#include <cstdint>

template <typename T>
class Stack {
   public:
    static constexpr size_t grow_coefficient = 2;
    static constexpr size_t default_capacity = 32;

    explicit Stack(size_t cap = default_capacity);
    Stack(const Stack<T> &another);
    Stack(Stack<T> &&another);
    ~Stack();

    void push(const T &val);
    void pop();
    const T &top() const;
    T &top();

    bool isEmpty() const;

   private:
    T *buff_;
    size_t cap_;
    size_t top_;

    T *allocate(size_t n) const;
    void deallocate(T *data) const;
};

using byte_t = uint8_t;

template <>
class Stack<bool> {
   public:
    static constexpr size_t grow_coefficient = 2;
    static constexpr size_t default_capacity = 32;

    explicit Stack(size_t cap = default_capacity);
    Stack(const Stack<bool> &another);
    Stack(Stack<bool> &&another);
    ~Stack();

    void push(bool val);
    void pop();
    bool top() const;

    bool isEmpty() const;

   private:
    byte_t *buff_;
    size_t cap_;
    size_t top_;

    byte_t *allocate(size_t n) const;
    void deallocate(byte_t *data) const;
};

#endif