#include <stdio.h>

// Recursive function to accept array elements
void acceptArrayElements(int arr[][100], int gr, int gc, int i, int j) {
    if (i == gr) {
        return; // Base case: All rows are filled
    }
    if (j == gc) {
        acceptArrayElements(arr, gr, gc, i + 1, 0); // Move to the next row
    } else {
        printf("Enter element for arr[%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
        acceptArrayElements(arr, gr, gc, i, j + 1); // Move to the next column
    }
}

// Recursive function to display array elements
void displayArrayElements(int arr[][100], int gr, int gc, int i, int j) {
    if (i == gr) {
        return; // Base case: All rows are displayed
    }
    if (j == gc) {
        printf("\n");
        displayArrayElements(arr, gr, gc, i + 1, 0); // Move to the next row
    } else {
        printf("%d ", arr[i][j]);
        displayArrayElements(arr, gr, gc, i, j + 1); // Move to the next column
    }
}

int main() {
    int r, c;

    // Input row and column sizes
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int arr[100][100]; // Fixed array size for simplicity

    // Accept and display array elements
    printf("Enter the elements of the array:\n");
    acceptArrayElements(arr, r, c, 0, 0);

    printf("The elements of the array are:\n");
    displayArrayElements(arr, r, c, 0, 0);

    return 0;
}
