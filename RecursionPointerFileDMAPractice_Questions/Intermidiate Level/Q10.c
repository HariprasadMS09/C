//Implement a program to resize a dynamically allocated array using realloc.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL; // Pointer for the dynamically allocated array
    int size = 0;    // Current size of the array
    int newSize, value;

    printf("Enter the initial size of the array: ");
    scanf("%d", &size);

    // Allocate initial memory for the array
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate the array with initial values
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Display the array
    printf("Current array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize the array
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);

    arr = (int *)realloc(arr, newSize * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // If the array is expanded, populate new elements
    if (newSize > size) {
        printf("Enter %d additional elements:\n", newSize - size);
        for (int i = size; i < newSize; i++) {
            printf("Element %d: ", i);
            scanf("%d", &arr[i]);
        }
    }

    // Display the updated array
    printf("Updated array:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
