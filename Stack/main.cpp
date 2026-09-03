#include <iostream>
#include "MyStack.h"

using namespace std;

int main() {

    cout << "========== STACK TEST ==========\n\n";

    MyStack<int> stack(3);

    // -------------------------------
    // 1. Initial State
    // -------------------------------
    cout << "Initial State:\n";
    cout << "Size     : " << stack.size() << '\n';
    cout << "Empty    : " << boolalpha << stack.isEmpty() << '\n';
    cout << "Full     : " << stack.isFull() << '\n';

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 2. Push Elements
    // -------------------------------
    cout << "Pushing 10, 20, 30...\n";

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Size     : " << stack.size() << '\n';
    cout << "Empty    : " << stack.isEmpty() << '\n';
    cout << "Full     : " << stack.isFull() << '\n';
    cout << "Top      : " << stack.peek() << '\n';

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 3. Test Resize
    // -------------------------------
    cout << "Stack is full. Pushing 40...\n";
    cout << "This should trigger resize.\n\n";

    stack.push(40);

    cout << "Size     : " << stack.size() << '\n';
    cout << "Empty    : " << stack.isEmpty() << '\n';
    cout << "Full     : " << stack.isFull() << '\n';
    cout << "Top      : " << stack.peek() << '\n';

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 4. Pop Elements
    // -------------------------------
    cout << "Popping elements:\n";

    cout << "Popped: " << stack.pop() << '\n';
    cout << "Popped: " << stack.pop() << '\n';

    cout << "\nAfter popping 2 elements:\n";
    cout << "Size     : " << stack.size() << '\n';
    cout << "Empty    : " << stack.isEmpty() << '\n';
    cout << "Full     : " << stack.isFull() << '\n';
    cout << "Top      : " << stack.peek() << '\n';

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 5. Pop Remaining Elements
    // -------------------------------
    cout << "Popping remaining elements:\n";

    while (!stack.isEmpty()) {
        cout << "Popped: " << stack.pop() << '\n';
    }

    cout << "\nAfter clearing stack:\n";
    cout << "Size     : " << stack.size() << '\n';
    cout << "Empty    : " << stack.isEmpty() << '\n';
    cout << "Full     : " << stack.isFull() << '\n';

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 6. Underflow Test
    // -------------------------------
    cout << "Testing pop() on empty stack:\n";

    try {
        stack.pop();
    }
    catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << '\n';
    }

    cout << "\n-------------------------------\n\n";


    // -------------------------------
    // 7. Top on Empty Stack
    // -------------------------------
    cout << "Testing top() on empty stack:\n";

    try {
        stack.peek();
    }
    catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << '\n';
    }

    cout << "\n================================\n";
    cout << "          TEST COMPLETE\n";
    cout << "================================\n";

    return 0;
}