#include <iostream>
#include <algorithm> // Required for std::swap

// Use the standard namespace
using namespace std;

class Maxheap {
public:
    int* arr;
    int size;
    int total_size;

    // Constructor
    Maxheap(int capacity) {
        arr = new int[capacity];
        size = 0;
        total_size = capacity;
    }

    // Destructor
    ~Maxheap() {
        delete[] arr;
    }

    void insert(int val) {
        if (size == total_size) {
            cout << "Heap is full: overflow!" << endl;
            return;
        }

        arr[size] = val;
        int currentIndex = size;
        size++;

        // Heapify-up
        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;

            if (arr[currentIndex] > arr[parentIndex]) {
                swap(arr[currentIndex], arr[parentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapify(int index) {
        int largest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest); // Recurse on the affected sub-tree
        }
    }

    void Delete() {
        if (size == 0) {
            cout << "Heap is empty: underflow!" << endl;
            return;
        }

        cout << "Element removed: " << arr[0] << endl;
        arr[0] = arr[size - 1];
        size--;

        if (size > 0) {
            heapify(0);
        }
    }

    void print() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// --- Main function to demonstrate and test the Maxheap ---
int main() {
    Maxheap heap(7); // Create a heap with a capacity of 7

    cout << "--- Building the Heap ---\n";
    heap.insert(50);
    heap.insert(30);
    heap.insert(70);
    heap.insert(20);
    heap.insert(90);
    heap.insert(60);
    heap.insert(80);
    heap.print();

    cout << "\n--- Testing Edge Cases ---\n";
    cout << "Attempting to insert into a full heap...\n";
    heap.insert(100); // Heap overflow test
    heap.print();

    cout << "\n--- Deleting All Elements ---\n";
    while (heap.size > 0) {
        heap.Delete();
        heap.print();
    }

    cout << "\n--- Testing Edge Cases (Again) ---\n";
    cout << "Attempting to delete from an empty heap...\n";
    heap.Delete(); // Heap underflow test

    return 0;
}