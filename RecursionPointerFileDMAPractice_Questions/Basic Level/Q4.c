//Create a program to read and display the contents of a file using fgetc.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define FILE_NAME "test.txt"

int main() {
    FILE *fptr;
    char txt[MAX_LENGTH];
    char ch;

    // Open file in write mode to create or overwrite content
    fptr = fopen(FILE_NAME, "w");
    if (fptr == NULL) {
        printf("Error: Could not open file %s for writing.\n", FILE_NAME);
        return 1;
    }

    printf("Enter the data (Max length: %d): ", MAX_LENGTH);
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0'; // Remove the newline character from input

    // Write the input to the file
    fprintf(fptr, "%s", txt);
    fclose(fptr);

    // Open file in read mode
    fptr = fopen(FILE_NAME, "r");
    if (fptr == NULL) {
        printf("Error: Could not open file %s for reading.\n", FILE_NAME);
        return 1;
    }

    printf("\nContents of the file %s:\n", FILE_NAME);

    // Read and display file contents using getc
    while ((ch = getc(fptr)) != EOF) {
        printf("%c", ch); // Display the character read by getc
    }

    fclose(fptr);
    return 0;
}
