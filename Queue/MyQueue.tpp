//#############\ Implementation /################


// constructor
template <typename T>
MyQueue<T>::MyQueue(int newCapacity){
    arr = new T[newCapacity];
    this -> capacity = newCapacity;
    this -> front = 0;
    this -> rear = -1;
}

// Destructor
template <typename T>
MyQueue<T>::~MyQueue(){
    delete[] arr;
}

// function which tells whether the queue is empty 
template <typename T>
bool MyQueue<T>::isEmpty(){
    return front > rear;
}

//function which tells whether the queue is full
template <typename T>
bool MyQueue<T>::isFull(){
    return rear == capacity - 1;
}

//function for resizing the queue (adding dynamic naturing)
template <typename T>
void MyQueue<T>::grow(int newCapacity){
    if(newCapacity <= capacity){
        throw std::invalid_argument("New size must be greater than current capacity");
    }

    T *newArr = new T[newCapacity];

    for(int i = front; i <= rear; i++){
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

//function which returns the front element
template <typename T>
T MyQueue<T>::frontElement(){
    if(!isEmpty()){
        return arr[front];
    } 
    throw std::out_of_range("Structure is empty!");
}

//function which return the  rear element
template <typename T>
T MyQueue<T>::rearElement(){
    if(!isEmpty()){
        return arr[rear];
    } 
    throw std::out_of_range("Structure is empty!");
}

// function which returns the size of the queue
template <typename T>
int MyQueue<T>::size(){
    if(isEmpty()){
    return 0;
    }
    return rear - front + 1;
}

//function to add element
template <typename T>
void MyQueue<T>::enqueue(T ele){

    //if space is not available
    if(isFull()){
        grow(capacity * 2);
    }
    
    //if space is available
    arr[++rear] = ele;
}

//function to remove element
template <typename T>
T MyQueue<T>::dequeue(){

    //if space is not available
    if(isEmpty()){
        throw std::out_of_range("Can't remove from an empty structure");
    }
    
    //if space is available
    return arr[front++];
}