
// Default constructor
template <typename T>
MyVector<T>::MyVector()
{
    currentCapacity = 1;
    currentSize = 0;
    data = new T[currentCapacity];
}

// Destructor
template <typename T>
MyVector<T>::~MyVector()
{
    // memory freed
    delete[] data;
}

// function for appending element at last position in the array
template <typename T>
void MyVector<T>::push_back(T value)
{
    // Space available
    if (currentSize < currentCapacity)
    {
        data[currentSize] = value;
        currentSize++;
    }
    // Space not available i.e Array is full
    else
    {

        // making newData array to allocate more memory
        int newCapacity = currentCapacity * 2;
        T *newData = new T[newCapacity];
        currentCapacity = newCapacity;

        // copy data of old array into new one
        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = data[i];
        }

        // delete the old data array
        delete[] data;

        // pointing data array to newData array
        data = newData;

        // Finally assign the value into the array
        data[currentSize] = value;
        currentSize++;
    }
}

// function for removing the last element from the array
//  returns the removed element
template <typename T>
T MyVector<T>::pop_back()
{

    // if array is already empty
    if (currentSize == 0)
    {
        throw std::out_of_range("Array is already empty");
    }

    T removedElement = data[currentSize - 1];
    currentSize--;
    return removedElement;
}

// function for finding size of the vector
// return the size of array
template <typename T>
int MyVector<T>::size()
{
    return currentSize;
}

// function for finding capacity of the vector
//  returns the capacity of the array
template <typename T>
int MyVector<T>::capacity()
{
    return currentCapacity;
}

// function for printing the whole array
template <typename T>
void MyVector<T>::print()
{
    if (currentSize == 0 || currentCapacity == 0)
    {
        std::cout << "Empty array" << std::endl;
        return;
    }

    for (auto it = begin(); it != end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

// return wether array is empty or not
template <typename T>
bool MyVector<T>::empty()
{
    return currentSize == 0;
}

// returns the last element
template <typename T>
T MyVector<T>::back()
{
    if (currentSize == 0)
    {
        throw std::out_of_range("Enter elements in the array");
    }
    return data[currentSize - 1];
}

// operator function to use square brackets []
template <typename T>
T &MyVector<T>::operator[](int idx)
{
    if (idx >= currentSize)
    {
        throw std::out_of_range("index is out of array range");
    }
    if (idx < 0)
    {
        throw std::out_of_range("Negative indexing is not allowed");
    }
    return data[idx];
}

// returns the first element of the array
template <typename T>
T MyVector<T>::front()
{
    if (currentSize != 0)
    {
        return data[0];
    }
    throw std::out_of_range("Array is empty");
}

// it clears all the element of the array
template <typename T>
void MyVector<T>::clear()
{
    currentSize = 0;
}

// returns the element of the array according to the index
template <typename T>
T MyVector<T>::at(int idx)
{
    if (idx < 0 || idx >= currentSize)
    {
        throw std::out_of_range("Index is out of bound");
    }
    return data[idx];
}

// it pre-reserve the capacity of the array for future use
template <typename T>
void MyVector<T>::reserve(int val)
{

    // requested capacity is already in range
    if (val <= currentCapacity)
    {
        return;
    }

    int newCapacity = val;
    T *newData = new T[newCapacity];
    currentCapacity = newCapacity;

    // copy data from old to new
    for (int i = 0; i < currentSize; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
}

// modify the size of the array
template <typename T>
void MyVector<T>::resize(int val)
{
    // requsted size is in current capacity
    if (val <= currentCapacity)
    {

        for (int i = currentSize; i < val; i++)
        {
            data[i] = T{};
        }
        currentSize = val;
        return;
    }

    // if size is not in capacity then we reserve with double space
    reserve(val * 2);

    for (int i = currentSize; i < val; i++)
    {
        data[i] = T{};
    }
    currentSize = val;
}

// inserting element at the desired position
template <typename T>
void MyVector<T>::insert(int pos, T val)
{

    if (pos < 0 || pos > currentSize)
    {
        throw std::out_of_range("Index is out of bound");
    }

    // if array is full then we resize it
    if (currentSize == currentCapacity)
    {
        resize(currentSize * 2);
    }

    // if space is available then we do shifiting of the elements to right
    for (int i = currentSize; i > pos; i--)
    {
        data[i] = data[i - 1];
    }
    data[pos] = val;
    currentSize++;
}

// erase function to remove the element at the desired position
template <typename T>
T MyVector<T>::erase(T pos)
{

    if (pos < 0 || pos >= currentSize)
    {
        throw std::out_of_range("Index is out of bound");
    }

    T removedElement = data[pos];

    // shifting the elements to left
    for (int i = pos; i < currentSize - 1; i++)
    {
        data[i] = data[i + 1];
    }
    currentSize--;
    return removedElement;
}

// Begin function which returns the iterator for the first element of the array
template <typename T>
T *MyVector<T>::begin()
{

    if (currentSize == 0)
    {
        throw std::out_of_range("Array is empty");
    }

    return data;
}

// End function which return the iterator for the last element of the array
template <typename T>
T *MyVector<T>::end()
{

    if (currentSize == 0)
    {
        throw std::out_of_range("Array is empty");
    }
    return data + currentSize;
}

// Copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &other)
{
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;
    data = new T[currentCapacity];

    for (int i = 0; i < currentSize; i++)
    {
        data[i] = other.data[i];
    }
}

// Self assignment operator
template <typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &other)
{
    if(this != &other)
    {
        delete[] data; // Free existing memory

        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;
        data = new T[currentCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Move constructor
template <typename T>
MyVector<T>::MyVector(MyVector<T> &&other) noexcept
    : data(other.data), 
      currentSize(other.currentSize), 
      currentCapacity(other.currentCapacity)
{
    other.data = nullptr; // Leave the moved-from object in a valid state
    other.currentSize = 0;
    other.currentCapacity = 0;
}

// Move assignment operator
template <typename T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &&other) noexcept
{
    if (this != &other)
    {
        delete[] data; // Free existing memory

        data = other.data;
        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;

        other.data = nullptr; // Leave the moved-from object in a valid state
        other.currentSize = 0;
        other.currentCapacity = 0;
    }
    return *this;
}

// ######################// Completed \\####################### //