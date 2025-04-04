//Create a program to copy the contents of one file to another.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileName "permanent.txt"
#define maxLength 100

void copy(char copiedTxt[]) {
    FILE *fptr;
    fptr = fopen(fileName, "r"); // Open file in read mode
    if (fptr == NULL) {
        printf("Error: Cannot open file in reading mode\n");
        exit(1);
    }

    printf("\nCopying data from %s...\n", fileName);
    char ch;
    int i = 0;
    while ((ch = fgetc(fptr)) != EOF && i < maxLength - 1) { // Copy character by character
        copiedTxt[i++] = ch;
    }
    copiedTxt[i] = '\0'; // Null-terminate the copied string

    fclose(fptr);
    printf("Data copied successfully.\n");
}

void paste(const char copiedTxt[], char tempFileName[]) {
    FILE *fptr;

    printf("Enter the file name to which the data should be pasted: ");
    scanf("%s", tempFileName);

    fptr = fopen(tempFileName, "w"); // Open file in write mode
    if (fptr == NULL) {
        printf("Error: Cannot open file in writing mode\n");
        exit(1);
    }

    fprintf(fptr, "%s", copiedTxt); // Write the copied content
    printf("Data pasted successfully into %s\n", tempFileName);

    fclose(fptr);
}

int main() {
    FILE *fptr;
    char txt[maxLength], copiedTxt[maxLength], tempFileName[maxLength];

    // Create and write to the source file
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        printf("Error: Cannot open file in writing mode\n");
        return 1;
    }

    printf("Enter the data (Max length: %d):\n", maxLength);
    getchar(); // Consume leftover newline character from stdin
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0'; // Remove newline character from the input

    fprintf(fptr, "%s", txt);
    fclose(fptr);
    printf("Data written to %s successfully.\n", fileName);

    // Copy and paste operations
    copy(copiedTxt);
    paste(copiedTxt, tempFileName);

    return 0;
}