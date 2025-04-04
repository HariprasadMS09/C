#include<stdio.h>
int main() {
    FILE *fptr;
    int i, n;

    printf("Enter the end number till where you want to find the list of odd numbers: \n");
    scanf("%d", &n);

    // Open file in write mode
    fptr = fopen("oddNum.txt", "w");
    if (fptr == NULL) {
        printf("Error: Can't open file.\n");
        return 1;
    }

    // Write odd numbers to the file
    for (i = 1; i <= n; i += 2) {
        fprintf(fptr, "%d\n", i);
    }
    fclose(fptr);
    printf("File updated successfully.\n");

    // Open file in read mode
    fptr = fopen("oddNum.txt", "r");
    if (fptr == NULL) {
        printf("Error: Can't open file.\n");
        return 1;
    }

    printf("Odd numbers from the file:\n");
    // Read and display numbers from the file
    while (fscanf(fptr, "%d", &i) != EOF) {
        printf("%d\n", i);
    }
    fclose(fptr);

    return 0;
}
