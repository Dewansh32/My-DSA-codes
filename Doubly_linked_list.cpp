#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};

class doublyList
{
    Node* head;
    Node* tail;

    public:
    doublyList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void push_back(int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        } 
        else if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;   
    }

    void pop_back()
    {
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        } 
        else if(head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }

    void remove_value(int val)
    {
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }
        if(temp == NULL)
        {
            cout<<"Element not found"<<endl;
            return;
        }
        else if(temp == head)
        {
            pop_front();
            return;
        }
        else if(temp == tail)
        {
            pop_back();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    int search(int key)
    {
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return -1;
        }   
        
        int count = 1;
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return count;
            }
            count++;
            temp = temp->next;
        }
        
        return -1;
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        } 
        Node* temp = head;
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
    doublyList dl;

    cout << "Pushing elements at front: 3, 2, 1" << endl;
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);
    dl.display();

    cout << "\nPushing elements at back: 4, 5" << endl;
    dl.push_back(4);
    dl.push_back(5);
    dl.display();

    cout << "\nPopping front element:" << endl;
    dl.pop_front();
    dl.display();

    cout << "\nPopping back element:" << endl;
    dl.pop_back();
    dl.display();

    cout << "\nSearching for 3:" << endl;
    int pos = dl.search(3);
    if(pos == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at position: " << pos << endl;

    cout << "\nRemoving value 3:" << endl;
    dl.remove_value(3);
    dl.display();

    cout << "\nRemoving non-existent value 99:" << endl;
    dl.remove_value(99);
    dl.display();

    cout << "\nPopping all to test empty state:" << endl;
    dl.pop_front();
    dl.pop_front();
    dl.pop_front();  // list should be empty now
    dl.display();

    cout << "\nTrying to pop again from empty list:" << endl;
    dl.pop_back();
    
    return 0;
}
