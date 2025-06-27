#include<iostream>
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

class circularList {
    Node* head;
    Node* tail;
public:
    circularList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }

        // Only one node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty, nothing to delete" << endl;
            return;
        }

        // Only one node
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = head;
        delete tail;
        tail = temp;
    }

    int search(int key)
    {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }
        Node* temp = head;
        int count = 1;
        do{
            if(temp->data == key)
            {
                return count;
            }
            temp = temp->next;
            count++;
        }while(temp != head);
            
        cout << "Element not in list" << endl;
        return -1;

    }

    void insertAtPosition(int val, int pos)
    {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(val);

        // Case 1: Insert at head
        if (pos == 1) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        int count = 1;

        // Traverse till node before desired position
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        // If position is beyond length + 1
        if (count < pos - 1) {
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return;
        }

        // Case 2: Insert at end (just before head, but after tail)
        if (temp == tail) {
            insertAtEnd(val);
            return;
        }

        // Case 3: Middle insertion
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int pos)
    {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        // Case 1: Delete head
        if (pos == 1) {
            deleteAtHead();
            return;
        }

        Node* temp = head;
        int count = 1;

        // Traverse to the node before the one to delete
        while (count < pos - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        // Invalid position
        if (temp->next == head || count < pos - 1) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node* delNode = temp->next;

        // Case 2: Delete tail
        if (delNode == tail) {
            tail = temp;
        }

        // Update the link and delete node
        temp->next = delNode->next;
        delete delNode;
    }


    void display() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        cout << head->data << "->";
        Node* temp = head->next;
        while (temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL->";
        cout << head->data << endl; // to show circular link
    }
};

int main() {
    circularList cl;
    cl.insertAtEnd(10);
    cl.insertAtEnd(20);
    cl.insertAtEnd(30);
    cl.insertAtHead(5);
    cl.display();

    cout << "After deleting head:\n";
    cl.deleteAtHead();
    cl.display();

    cout << "After deleting end:\n";
    cl.deleteAtEnd();
    cl.display();

    return 0;
}
