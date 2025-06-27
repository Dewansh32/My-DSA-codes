#include <iostream>
using namespace std;

constexpr int N = 5;  // 🧠 Constant evaluated at compile-time

class Stack {
    int arr[N];
    int top;

public:
    Stack() : top(-1) {}

    bool isFull() const {
        return top == N - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push() {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            arr[++top] = val;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "Popped value: " << arr[top--] << endl;
        }
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements are:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
};

int main() {
    Stack s;
    int ch;

    do {
        cout << "\nEnter choice:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 0);

    return 0;
}
