#include<iostream>
using namespace std;

constexpr int N=5;

class queue
{
    public:
    int queue[N];
    int front=-1,rear=-1;
    
    void enqueue(int val)
    {
        if(rear == N-1)
        {
            cout<<"Overflow condition"<<endl;
        }
        else if(front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear]=val;
        }
        else{
            rear++;
            queue[rear]=val;
        }
    }

    void dequeue()
    {
        if(front == -1 && rear == -1)
        {
            cout<<"Underflow: Queue is empty"<<endl;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else{
            cout<<"Element to dequeue: "<<queue[front]<<endl;
            front++;
        }
    }

    void peek()
    {
        if (front == -1 && rear == -1) 
        {
            cout << "Queue is empty" << endl;
        } 
        else{
            cout<<"Front element: "<<queue[front]<<endl;
        }

    }

    void display() {
        if (front == -1 && rear == -1) 
        {
            cout << "Queue is empty" << endl;
        } 
        else 
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);  // Should work
    q.enqueue(60);  // Should show "Overflow"

    q.dequeue();

    q.display();  // Let's see what's inside the queue

    return 0;

}