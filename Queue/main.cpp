#include <iostream>
#include <exception>
#include "MyQueue.h"

using namespace std;

int main() {

    cout << "========== QUEUE TEST ==========\n\n";

    MyQueue<int> q(3);

    // --------------------------------
    // 1. Initial State
    // --------------------------------
    cout << "Initial State:\n";
    cout << "Size     : " << q.size() << '\n';
    cout << "Empty    : " << boolalpha << q.isEmpty() << '\n';
    cout << "Full     : " << q.isFull() << '\n';

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 2. Enqueue
    // --------------------------------
    cout << "Enqueueing 10, 20, 30...\n";

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Size     : " << q.size() << '\n';
    cout << "Empty    : " << q.isEmpty() << '\n';
    cout << "Full     : " << q.isFull() << '\n';
    cout << "Front    : " << q.frontElement() << '\n';
    cout << "Rear     : " << q.rearElement() << '\n';

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 3. Automatic Resize
    // --------------------------------
    cout << "Queue is full. Enqueueing 40...\n";
    cout << "This should trigger resize.\n\n";

    q.enqueue(40);

    cout << "Size     : " << q.size() << '\n';
    cout << "Empty    : " << q.isEmpty() << '\n';
    cout << "Full     : " << q.isFull() << '\n';
    cout << "Front    : " << q.frontElement() << '\n';
    cout << "Rear     : " << q.rearElement() << '\n';

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 4. Dequeue
    // --------------------------------
    cout << "Dequeueing elements:\n";

    cout << "Dequeued : " << q.dequeue() << '\n';
    cout << "Dequeued : " << q.dequeue() << '\n';

    cout << "\nAfter dequeueing 2 elements:\n";
    cout << "Size     : " << q.size() << '\n';
    cout << "Empty    : " << q.isEmpty() << '\n';
    cout << "Full     : " << q.isFull() << '\n';
    cout << "Front    : " << q.frontElement() << '\n';
    cout << "Rear     : " << q.rearElement() << '\n';

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 5. FIFO Verification
    // --------------------------------
    cout << "Testing FIFO behaviour:\n";

    cout << "Dequeued : " << q.dequeue() << '\n';
    cout << "Dequeued : " << q.dequeue() << '\n';

    cout << "\nAfter removing everything:\n";
    cout << "Size     : " << q.size() << '\n';
    cout << "Empty    : " << q.isEmpty() << '\n';
    cout << "Full     : " << q.isFull() << '\n';

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 6. Underflow Test - dequeue()
    // --------------------------------
    cout << "Testing dequeue() on empty queue:\n";

    try {
        q.dequeue();
    }
    catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << '\n';
    }

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 7. Underflow Test - front()
    // --------------------------------
    cout << "Testing frontElement() on empty queue:\n";

    try {
        q.frontElement();
    }
    catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << '\n';
    }

    cout << "\n-------------------------------\n\n";


    // --------------------------------
    // 8. Underflow Test - rear()
    // --------------------------------
    cout << "Testing rearElement() on empty queue:\n";

    try {
        q.rearElement();
    }
    catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << '\n';
    }

    cout << "\n================================\n";
    cout << "          TEST COMPLETE\n";
    cout << "================================\n";

    return 0;
}