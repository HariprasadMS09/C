//Matrix multiplication

#include <stdio.h>

void takeInput(int mat[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("[%d][%d] : ", i, j);
            scanf("%d", &mat[i][j]); // Corrected scanf and loop condition
        }
    }
}

void addAndDisplayMatrix(int mat1[][100], int mat2[][100], int res[][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("The resultant matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[100][100], mat2[100][100], res[100][100];
    int r, c;

    printf("Row size: ");
    scanf("%d", &r); // Removed \n
    printf("Column size: ");
    scanf("%d", &c); // Removed \n

    printf("Enter mat1 elements:\n");
    takeInput(mat1, r, c);
    printf("Enter mat2 elements:\n");
    takeInput(mat2, r, c);

    addAndDisplayMatrix(mat1, mat2, res, r, c);

    return 0;
}
