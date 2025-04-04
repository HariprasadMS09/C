#include <stdio.h>

void acceptArrayElements(int arr[][100], int gr, int gc, int i, int j) {
    if (i == gr) return; // Base case: All rows are filled
    if (j == gc) {
        acceptArrayElements(arr, gr, gc, i + 1, 0); // Move to the next row
    } else {
        printf("Enter element for arr[%d][%d]: ", i, j);
        scanf("%d", &arr[i][j]);
        acceptArrayElements(arr, gr, gc, i, j + 1); // Move to the next column
    }
}

void addAndDisplayArrays(int arr1[][100], int arr2[][100], int gr, int gc, int i, int j) {
    if (i == gr) return; // Base case: All rows are processed
    if (j == gc) {
        printf("\n");
        addAndDisplayArrays(arr1, arr2, gr, gc, i + 1, 0); // Move to the next row
    } else {
        printf("%d\t", arr1[i][j] + arr2[i][j]); // Add and display the elements
        addAndDisplayArrays(arr1, arr2, gr, gc, i, j + 1); // Move to the next column
    }
}

int main() {
    int r, c;
    printf("Enter row and column size: ");
    scanf("%d %d", &r, &c);

    int arr1[100][100], arr2[100][100];

    printf("Enter Array 1 elements:\n");
    acceptArrayElements(arr1, r, c, 0, 0);

    printf("Enter Array 2 elements:\n");
    acceptArrayElements(arr2, r, c, 0, 0);

    printf("The resultant array is:\n");
    addAndDisplayArrays(arr1, arr2, r, c, 0, 0);

    return 0;
}
