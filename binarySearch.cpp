#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target element found at index mid
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    
    int result = binarySearch(arr, 0, size - 1, target);
    
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    
    return 0;
}
