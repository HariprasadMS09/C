//Write a program to demonstrate a dangling pointer and how to avoid it.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *ptr; // Declare the pointer

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program
    }

    // Assign values to the allocated memory
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("ptr[%d]: ", i);
        scanf("%d", &ptr[i]); // Use &ptr[i] to correctly input values
    }

    // Print the values before freeing memory
    printf("Values before freeing up the memory:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]); // Use ptr[i] to correctly access values
    }
    printf("\n");

    // Free the memory
    free(ptr);

    // Simulating dangling pointer access (undefined behavior)
    // WARNING: Accessing *ptr after free leads to undefined behavior
    // Commented out to avoid undefined behavior:
    printf("Accessing memory after free (undefined behavior): %d\n", *ptr);

    // Avoid dangling pointer by setting ptr to NULL
    printf("Fixing the dangling pointer issue.....\n\n");
    ptr = NULL;

    if (ptr == NULL) {
        printf("Pointer is now NULL and safe to use.\n");
    }

    return 0;
}
