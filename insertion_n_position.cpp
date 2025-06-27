#include <iostream>
using namespace std;

int main() {
    int arr[100] = {5, 7, 10, 4, 7}; // Increased size to allow insertion
    int sz = 5; // Only first 5 elements are valid

    int pos;
    cout << "Enter position where you want to add the new number (1 to " << sz + 1 << "): ";
    cin >> pos;

    // Position validation
    if(pos < 1 || pos > sz + 1) {
        cout << "Invalid position!" << endl;
        return 1;
    }

    int num;
    cout << "Enter the number you want to add: ";
    cin >> num;

    // Shift elements to the right
    for(int i = sz - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new number
    arr[pos - 1] = num;
    sz++;

    cout << "Array after insertion: ";
    for(int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
