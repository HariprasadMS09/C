//Implement a program to dynamically allocate memory for a 2D matrix, take input, and print the matrix.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    int *mat;

    printf("Enter row and column size respectively: ");
    scanf("%d %d", &r, &c); // Corrected: Removed `\t` from format specifier.

    // Allocate memory for the entire matrix
    mat = (int *)malloc(r * c * sizeof(int));
    if (mat == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i * c + j]); // Corrected: Use `i * c + j` to calculate the correct index.
        }
    }

    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat[i * c + j]); // Corrected: Use `i * c + j` to calculate the correct index.
        }
        printf("\n");
    }

    // Free allocated memory
    free(mat);

    return 0;
}