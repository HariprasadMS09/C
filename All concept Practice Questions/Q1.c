//Reversing a given string witout using library function
#include <stdio.h>

void main() {
    char str[100], rev[100];
    int i, l=0;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character if present
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
    }

    // Calculate the length of the string
    for (i = 0; str[i] != '\0'; i++) {
        l++;
    }

    // Reverse the string
    for (i = 0; i < l; i++) {
        rev[i] = str[l - i - 1];
    }
    rev[l] = '\0'; // Null-terminate the reversed string

    // Print the reversed string
    printf("Reversed string: %s\n", rev);

}
