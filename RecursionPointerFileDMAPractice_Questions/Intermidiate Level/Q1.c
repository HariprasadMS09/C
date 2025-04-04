//Implement a recursive binary search function for an integer array.
#include <stdio.h>

// Function to perform recursive binary search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        // Base case: If the range is invalid, the target is not in the array
        return -1;
    }

    int mid = low + (high - low) / 2; // Calculate the middle index

    if (arr[mid] == target) {
        // Base case: If the target is found, return its index
        return mid;
    } else if (arr[mid] > target) {
        // Recursive case: Search the left half
        return binarySearch(arr, low, mid - 1, target);
    } else {
        // Recursive case: Search the right half
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {
    int n, target;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements in sorted order
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
