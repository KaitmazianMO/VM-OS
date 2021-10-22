#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <typename T>
class Stack
{
public:
    static constexpr size_t grow_coefficient = 2;

    explicit Stack (size_t cap = 32);
    Stack (const Stack<T>& another);
    Stack (Stack<T>&& another);
   ~Stack();

    void push (const T& val);
    void pop(); 
    const T& top() const;
    T& top();

    bool isEmpty() const;

private:
    T *buff_;
    size_t cap_;
    size_t top_;

    T *allocate (size_t n) { return new T[n]; };
    void deallocate (T *data) { delete [] data; };
};

#endif