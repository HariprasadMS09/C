//Implement a function to reverse a string using recursion.
#include <stdio.h>
#include <string.h>

#define maxLength 100

// Recursive function to reverse a string
void reverseStr(char orgStr[], char revStr[], int l, int index) {
    if (index < 0) { // Base case: end of recursion
        revStr[l] = '\0'; // Null-terminate the reversed string
        return;
    }
    revStr[l - index - 1] = orgStr[index]; // Assign character in reverse order
    reverseStr(orgStr, revStr, l, index - 1); // Recursive call
}

int main() {
    char orgStr[maxLength], revStr[maxLength];
    int l = 0;

    printf("Enter a text (Max length = %d): ", maxLength);
    fgets(orgStr, sizeof(orgStr), stdin);

    // Remove the newline character added by fgets
    orgStr[strcspn(orgStr, "\n")] = '\0';

    // Calculate the length of the input string
    while (orgStr[l] != '\0') {
        l++;
    }

    // Reverse the string using recursion
    reverseStr(orgStr, revStr, l, l - 1);

    printf("Reversed text: ");
    fputs(revStr, stdout);

    return 0;
}
