// ############/ Implementation of MyStack class /############

// constructor
template <typename T>
MyStack<T>::MyStack(int size)
{
    this->capacity = size;
    this->top = -1;
    this->arr = new T[capacity];
}

// destructor
template <typename T>
MyStack<T>::~MyStack()
{
    delete[] arr;
}

// function for checking if the stack is empty
template <typename T>
bool MyStack<T>::isEmpty()
{
    return top == -1;
}

// function for checking if the stack is full
template <typename T>
bool MyStack<T>::isFull()
{
    return top == capacity - 1;
}

// function for resizing the stack
template <typename T>
void MyStack<T>::resize(int newSize)
{

    if (newSize <= capacity)
    {
        throw std::invalid_argument("New size must be greater than current capacity.");
    }

    T *newArr = new T[newSize];

    for (int i = 0; i <= top; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newSize;
}

// function to add an element at the top of the stack
template <typename T>
void MyStack<T>::push(T val)
{

    // check if the stack is full
    if (isFull())
    {
        resize(capacity * 2); // double the size of the stack
        arr[++top] = val;
        return;
    }

    arr[++top] = val;
}

// function to remove an element from the top of the stack
template <typename T>
T MyStack<T>::pop()
{
    // checks if the stack is empty
    if (isEmpty())
    {
        throw std::out_of_range("Stack underflow: Cannot pop from an empty stack.");
    }
    return arr[top--];
}

// function to return the size of the stack
template <typename T>
int MyStack<T>::peek()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack underflow: Cannot access top element in empty stack");
    }
    return arr[top];
}

// function to return the size of the stack
template <typename T>
int MyStack<T>::size()
{
    if (isEmpty())
    {
        return 0;
    }
    return top + 1;
}

template <typename T>
void MyStack<T>::display()
{
    if (!isEmpty())
    {
        std::cout << "Stacks element are: ";
        for (int i = top; i >= 0; i--)
        {
            std::cout << arr[i] << " ";
        }
    }
}

