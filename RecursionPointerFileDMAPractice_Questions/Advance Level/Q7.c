//Create a program to demonstrate pointer-to-pointer usage in dynamic memory allocation for a 2D matrix.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    int **ptr; // Pointer-to-pointer for dynamic 2D array

    // Get the matrix size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Allocate memory for row pointers
    ptr = (int **)malloc(r * sizeof(int *));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Allocate memory for each row
    for (int i = 0; i < r; i++) {
        ptr[i] = (int *)malloc(c * sizeof(int));
        if (ptr[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i);
            return 1;
        }
    }

    // Input elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &ptr[i][j]); // Access dynamically allocated array
        }
    }

    // Display matrix
    printf("\nMatrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < r; i++) {
        free(ptr[i]); // Free each row
    }
    free(ptr); // Free row pointers

    return 0;
}
