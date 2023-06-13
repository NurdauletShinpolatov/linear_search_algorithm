#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

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

// Parallel hybrid search function
int parallelHybridSearch(const std::vector<int>& arr, int target, int numThreads) {
    int chunkSize = arr.size() / numThreads;
    std::vector<std::future<int>> results;
    
    for (int i = 0; i < numThreads; ++i) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? arr.size() : (i + 1) * chunkSize;
        std::vector<int> subset(arr.begin() + start, arr.begin() + end);
        
        if (i % 2 == 0) {
            // Use linear search for even subsets
            results.push_back(std::async(std::launch::async, linearSearch, subset, target));
        } else {
            // Use binary search for odd subsets
            results.push_back(std::async(std::launch::async, binarySearch, subset, target));
        }
    }
    
    // Collect the results from all threads
    std::vector<int> indices;
    for (auto& result : results) {
        indices.push_back(result.get());
    }
    
    // Merge or aggregate the results to obtain the final search output
    auto it = std::find_if(indices.begin(), indices.end(), [](int index) { return index != -1; });
    if (it != indices.end()) {
        return std::distance(indices.begin(), it) * chunkSize + *it;
    }
    
    return -1;
}

int main() {
    std::vector<int> dataset = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int numThreads = 4;

    int index = parallelHybridSearch(dataset, target, numThreads);

    if (index != -1) {
        std::cout << "Target found at index " << index << "." << std::endl;
    } else {
        std::cout << "Target not found in the dataset." << std::endl;
    }

    return 0;
}
