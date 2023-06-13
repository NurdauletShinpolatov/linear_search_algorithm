def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Return the index where the target element is found
    return -1  # Return -1 if the target element is not found

arr = [5, 2, 8, 12, 3]
target = 8

result = linear_search(arr, target)

if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found in the list")
