//Use file handling to count the number of words, lines, and characters in a file.
#include<stdio.h>
#include<stdlib.h>

#define maxLength 100

int main() {
    int words = 0, lines = 1, chars = 0;
    char fileName[maxLength], copiedTxt[maxLength];
    FILE *fptr;

    printf("Enter the file name to open: ");
    scanf("%s", fileName);

    // Open the file
    fptr = fopen(fileName, "r");
    if (fptr == NULL) {
        printf("\nError: Cannot open file %s\n", fileName);
        return 1;
    }

    char ch;
    int i = 0, inWord = 0;

    // Read character by character
    while ((ch = fgetc(fptr)) != EOF && i < maxLength - 1) {
        copiedTxt[i++] = ch;
        chars++; // Count every character

        // Check if the character is a newline
        if (ch == '\n') {
            lines++;
        }

        // Check for word boundaries
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0; // Outside of a word
        } else if (inWord == 0) {
            inWord = 1; // Starting a new word
            words++;
        }
    }

    copiedTxt[i] = '\0'; // Null-terminate the copied text

    // Print the copied text
    printf("\nData inside %s:\n%s\n", fileName, copiedTxt);

    // Print the counts
    printf("\nThere are %d words, %d lines, and %d characters in that data\n", words, lines, chars);

    fclose(fptr); // Close the file
    return 0;
}
