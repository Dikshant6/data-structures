#ifndef MY_QUEUE_H
#define MY_QUEUE_H

template <typename T>

class MyQueue{
    private:
    T* arr;
    int rear;
    int front;
    int capacity;

    public:
    
    MyQueue(int newCapacity); // parameterised constructor
    ~MyQueue(); // destructor

    // Methods
    void enqueue(T ele);
    T dequeue();
    T frontElement();
    T rearElement();
    void grow(int newCapacity);
    bool isEmpty();
    bool isFull();
    int size();

};

#include "MyQueue.tpp"
#endif