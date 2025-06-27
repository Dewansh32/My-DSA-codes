#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class list{
    Node* head;
    Node* tail;

    public:
    list() {
        head = tail =NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if(head == NULL)
        {
            cout<<"The linked list is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        
        delete temp;
    }

    void pop_back()
    {
        if(head == NULL)
        {
            cout<<"The linked list is empty"<<endl;
            return;
        }

        if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }


    void insert(int val,int pos)
    {
        if(pos < 0){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos == 1){
            push_front(val);
            return; // 🛑 this is necessary
        }

        Node* temp = head;
        for(int i = 1; i < pos - 1; i++)
        {
            if(temp == NULL) // 🛑 extra safety
            {
                cout << "Position out of bounds" << endl;
                return;
            }
            temp = temp->next;
        }

        if(temp == NULL) // in case position is exactly one after tail
        {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        // If we added at the end, update tail
        if(newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    int search(int key)
    {
        Node* temp = head;
        if(head == NULL)
        {
            cout<<"Empty linked list"<<endl;
        }

        int count = 1;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return count;
            }

            temp = temp->next;
            count++;
        }

        return -1;
    }

    void reverse_ll()
    {
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void print_ll()
    {
        Node* temp = head;
        while(temp != NULL)
        {
            cout<< temp->data <<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(4);
    ll.push_back(5);

    ll.print_ll();

    ll.reverse_ll();

    ll.print_ll();

    return 0;
}