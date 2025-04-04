//Write a program that demonstrates the use of pointer arithmetic to traverse and modify an array.

#include <stdio.h>

void modifyArray(int *arr, int size) {
    int *ptr = arr; // Pointer to the beginning of the array

    printf("Original array values:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i)); // Access elements using pointer arithmetic
    }
    printf("\n");

    // Modify array elements
    for (int i = 0; i < size; i++) {
        *(ptr + i) += 10; // Add 10 to each element
    }

    printf("Modified array values:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(ptr + i)); // Access modified elements
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Traversing and modifying the array using pointer arithmetic.\n");
    modifyArray(arr, size);

    return 0;
}
