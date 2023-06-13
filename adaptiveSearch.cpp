#include <iostream>
#include <vector>

// Linear search implementation
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary search implementation
int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

// Interpolation search implementation
int interpolationSearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    
    return -1;
}

// Adaptive search function
int adaptiveSearch(const std::vector<int>& arr, int target) {
    if (arr.size() < 1000) {
        // Use linear search for small datasets
        return linearSearch(arr, target);
    } else {
        // Check if the dataset is uniformly distributed
        // Replace this with your own logic to determine the dataset distribution
        bool isUniformlyDistributed = true;
        
        if (isUniformlyDistributed) {
            // Use linear search for uniformly distributed larger datasets
            return linearSearch(arr, target);
        } else {
            // Use binary search for non-uniformly distributed larger datasets
            return binarySearch(arr, target);
        }
    }
}

int main() {
    std::vector<int> dataset = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;

    int index = adaptiveSearch(dataset, target);

    if (index != -1) {
        std::cout << "Target found at index " << index << "." << std::endl;
    } else {
        std::cout << "Target not found in the dataset." << std::endl;
    }

    return 0;
}
