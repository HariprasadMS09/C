//Create a program to write a string to a file and then read it back using fprintf and fscanf.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define fileName "test.txt"
#define maxLength 100

int main() {
    char inTxt[maxLength], outTxt[maxLength];
    FILE *fptr;

    // Open the file in write mode
    fptr = fopen(fileName, "w");
    if (fptr == NULL) {
        printf("File not found or file cannot open in writing mode\n");
        return 1;
    }

    // Get input from the user
    printf("Enter the data: ");
    fgets(inTxt, sizeof(inTxt), stdin);
    inTxt[strcspn(inTxt, "\n")] = '\0'; // Remove trailing newline

    // Write to the file
    fprintf(fptr, "%s", inTxt);
    fclose(fptr); // Close the file after writing

    // Open the file in read mode
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("File not found or file cannot open in reading mode\n");
        return 1;
    }

    // Read from the file
    fscanf(fptr, "%[^\0]", outTxt); // Read until newline
    fclose(fptr); // Close the file after reading

    // Print the read string
    printf("String read from the file: %s\n", outTxt);

    return 0;
}
