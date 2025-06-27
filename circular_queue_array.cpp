#include<iostream>
using namespace std;

constexpr int N = 5;

class Queue
{
    int queue[N];
    int front = -1;
    int rear = -1;

public:
    void push(int val)
    {
        if ((rear + 1) % N == front)
        {
            cout << "Queue is full ❌" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = val;
        }
        else
        {
            rear = (rear + 1) % N;
            queue[rear] = val;
        }
    }

    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is already empty 🕳️" << endl;
        }
        else if (front == rear)
        {
            cout << "Element to be deleted: " << queue[front] << endl;
            front = rear = -1;
        }
        else
        {
            cout << "Element to be deleted: " << queue[front] << endl;
            front = (front + 1) % N;
        }
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty 🫥" << endl;
        }
        else
        {
            int i = front;
            cout << "Queue: ";
            while (i != rear)
            {
                cout << queue[i] << " ";
                i = (i + 1) % N;
            }
            cout << queue[rear] << endl;
        }
    }

    void peek()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty 👻" << endl;
        }
        else
        {
            cout << "Front element: " << queue[front] << endl;
        }
    }
};

int main()
{
    Queue q;

    // Testing circular queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);  // Will be full after 4 elements due to circular logic

    q.display();  // Should print: 10 20 30 40

    q.dequeue();  // Removes 10
    q.dequeue();  // Removes 20

    q.display();  // Should print: 30 40

    q.push(60);   // Now room is available
    q.push(70);   // Uses circular nature

    q.display();  // Should print: 30 40 60 70

    q.push(80);   // Should print "Queue is full ❌"

    q.peek();     // Should show: 30

    return 0;
}
