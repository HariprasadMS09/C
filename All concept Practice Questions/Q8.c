#include <stdio.h>
#define maxSize 100

int main() {
    char orgStr[maxSize], revStr[maxSize];
    int l = 0, isPalindrome = 1; // Flag to check if palindrome

    printf("Enter a string (Max Size: %d): ", maxSize);
    fgets(orgStr, sizeof(orgStr), stdin);

    // Calculate length of the string (excluding the newline character)
    while (orgStr[l] != '\n' && orgStr[l] != '\0') {
        l++;
    }
    orgStr[l] = '\0'; // Remove newline and terminate string properly

    // Reverse the string
    for (int i = 0; i < l; i++) {
        revStr[i] = orgStr[l - i - 1];
    }
    revStr[l] = '\0'; // Null-terminate the reversed string

    // Check if original and reversed strings are the same
    for (int i = 0; i < l; i++) {
        if (orgStr[i] != revStr[i]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
    }

    // Print result
    if (isPalindrome) {
        printf("The given string is a palindrome.\n");
    } else {
        printf("The given string is not a palindrome.\n");
    }

    return 0;
}