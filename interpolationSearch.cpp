#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        
        if (arr[pos] == target) {
            return pos; // Target element found at index pos
        }
        
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
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
    
    int result = interpolationSearch(arr, size, target);
    
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    
    return 0;
}
