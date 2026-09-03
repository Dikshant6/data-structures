#ifndef MY_STACK_H
#define MY_STACK_H

template <typename T>

class MyStack
{

private:
    int capacity;
    int top;
    T *arr;

public:
    // constructors and destructors
    MyStack(int size);
    ~MyStack();

    // stack methods
    void push(T val);
    void resize(int newSize);
    void display();
    T pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int size();
};

#include "myStack.tpp"
#endif