#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>

class MyVector
{
private:
    T *data;
    int currentSize;
    int currentCapacity;

public:
    MyVector(); // default constructor
    ~MyVector(); // Destructor
    MyVector(const MyVector &other); // copy constructor
    MyVector& operator=(const MyVector<T> &other); // self assignment operator
    MyVector(MyVector &&other) noexcept; // move constructor
    MyVector& operator=(MyVector &&other) noexcept; // move assignment operator

    void push_back(T val);
    T pop_back();

    int size();
    int capacity();

    void print();
    bool empty();
    void clear();
    void reserve(int value);
    void resize(int value);

    T erase(T pos);
    void insert(int pos, T val);
    T at(int idx);
    T front();
    T back();
    T &operator[](int idx);
    T *begin();
    T *end();
};

#include "MyVector.tpp"
#endif