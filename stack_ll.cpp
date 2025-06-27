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

class stack
{
    Node* top;
    public:
    stack(){
        top = NULL;
    }

    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        Node* temp = top;
        if(top == NULL)
        {
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<<"data cleared is: "<<top->data<<endl;
            top =  top->next;
            delete temp;
        }
    }

    void peek()
    {
        if(top == NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<"Topmost element: "<<top->data<<endl;
        }
    }

    void display()
    {
        Node* temp = top;
        while(temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.display();

    s.peek();

    s.pop();
    s.display();

    return 0;
}