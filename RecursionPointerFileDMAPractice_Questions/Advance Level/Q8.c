//Use recursion to find all subsets of a given set of integers.

#include <stdio.h>

#define maxSize 100

// Function to print a subset
void printSubSet(int subSet[], int subSetSize) {
    printf("{ ");
    for (int i = 0; i < subSetSize; i++) {
        printf("%d ", subSet[i]); // Adding space for clarity
    }
    printf("}\n");
}

// Recursive function to generate all subsets
void findSubSet(int arr[], int subSet[], int n, int index, int subSetSize) {
    if (index == n) { // Base case: When all elements are processed
        printSubSet(subSet, subSetSize);
        return;
    }

    // Include the current element
    subSet[subSetSize] = arr[index];
    findSubSet(arr, subSet, n, index + 1, subSetSize + 1);

    // Exclude the current element
    findSubSet(arr, subSet, n, index + 1, subSetSize);
}

int main() {
    int arr[maxSize], subSet[maxSize];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("All subsets of arr are....\n");
    findSubSet(arr, subSet, n, 0, 0);

    return 0;
}
