#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class list {
    Node* head;
    Node* tail;

public:
    list() {
        head = tail = NULL;
    }

    ~list() {
        // clean up
        while (head != NULL) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) {
            cout << "The linked list is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL)          // if list became empty
            tail = NULL;
        delete temp;
    }

    void pop_back() {
        if (head == NULL) {
            cout << "The linked list is empty" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 1) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void remove(int key)
    {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        else if(head->data == key)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        else{
            Node* temp = head;
            Node* pre = NULL;
            while(temp->next != NULL && temp->data != key)
            {
                pre = temp;
                temp = temp->next;
            }
            if(temp->next == NULL && temp->data != key)
            {
                cout<<"Element not found"<<endl;
                return;
            }
            else
            {
                pre->next = temp->next;
                delete temp;
            }
        }
    }

    void delete_pos(int pos)
    {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        else if(pos<=0)
        {
            cout<<"Position invalid"<<endl;
            return;
        }
        else if(pos == 1)
        {
            pop_front();
            return;
        }
        else{
            Node* temp = head;
            Node* pre = NULL;
            int i = 1;
            while(i != pos && temp != NULL)
            {
                pre = temp;
                temp = temp->next;
                i++;
            }
            if(temp == NULL)
            {
                cout<<"Position out of bounds"<<endl;            
            }
            else{
                pre->next = temp->next;
                delete temp;
            }
            
        }

    }

    int search(int key) {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return -1;
        }
        Node* temp = head;
        int count = 1;
        while (temp != NULL) {
            if (temp->data == key)
                return count;
            temp = temp->next;
            count++;
        }
        return -1;
    }

    void print_ll() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    list ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);
    ll.push_back(5);

    cout << "Initial list: ";
    ll.print_ll();

    ll.pop_front();
    cout << "After popping front: ";
    ll.print_ll();

    ll.pop_back();
    cout << "After popping back: ";
    ll.print_ll();

    ll.insert(6, 1);
    cout << "After insertion: ";
    ll.print_ll();

    int pos = ll.search(5);
    if (pos == -1)
        cout << "Key doesn't exist" << endl;
    else
        cout << "Desired position is: " << pos << endl;

    return 0;
}
