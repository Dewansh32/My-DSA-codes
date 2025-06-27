#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    Node* front = NULL;
    Node* rear = NULL;
    public:
    void enqueue(int val)
    {
        Node* newNode = new Node(val);
        if(front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if(front == NULL && rear == NULL)
        {
            cout<<"Underflow: queue is empty"<<endl;
        }
        else{
            Node* temp = front;
            cout<<"Data to be deleted: "<<front->data<<endl;
            front = front->next;
            delete temp;

            if (front == NULL) {
            // Queue became empty, so update rear too
                rear = NULL;
            }
        }
    }

    void peek()
    {
        if(front == NULL && rear == NULL)
        {
            cout<<"Underflow: queue is empty"<<endl;
        }
        else{
            cout<<"data at front is: "<<front->data<<endl;
        }   
    }

    void display()
    {
        if(rear == 0 && front == 0)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();

    q.dequeue();
    q.display();

    q.peek();

    return 0;
}