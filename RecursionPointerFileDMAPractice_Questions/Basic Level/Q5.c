//Write a program to dynamically allocate memory for an integer array and populate it with user input.
#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main() {
    int n, *arr;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) { // Check if memory allocation failed
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate the array with user input
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the contents of the array
    printf("\nThe elements in the array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
