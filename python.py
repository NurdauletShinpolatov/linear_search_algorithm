#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i; // Return the index where the target element is found
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    vector<int> vec = {5, 2, 8, 12, 3};
    int target = 8;

    int result = linearSearch(vec, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the vector" << endl;
    }

    return 0;
}
