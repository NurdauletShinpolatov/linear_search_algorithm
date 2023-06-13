#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target element found at index i
        }
    }
    return -1; // Target element not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int target;
    cout << "Enter the element you are searching for: ";
    cin >> target;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);

    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}
