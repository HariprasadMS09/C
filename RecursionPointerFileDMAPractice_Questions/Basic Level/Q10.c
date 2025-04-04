//Dynamically allocate memory for a string, accept input, and display the string.
#include <stdio.h>
#include <stdlib.h>

#define maxLength 100

int main() {
    char *txt;

    // Allocate memory dynamically
    txt = (char *)malloc(maxLength * sizeof(char));
    if (txt == NULL) { // Check if memory allocation succeeded
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the text: ");
    fgets(txt, maxLength, stdin); // Correct usage of fgets

    printf("Entered text : %s", txt);
    
    free(txt);

    return 0;
}