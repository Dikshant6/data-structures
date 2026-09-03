#include <iostream>
#include "MyVector.h"

int main()
{
    MyVector<int> a;

    a.push_back(10);
    a.push_back(20);

    MyVector<int> b = std::move(a);

    b.print();
    std::cout << a.size() << std::endl;

    return 0;
}