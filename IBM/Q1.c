#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void compressString(char *input, char *output) {
    int i = 0, j = 0, count = 1;

    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            // Handle alphabetic characters
            output[j++] = input[i];
            while (input[i] == input[i + 1]) {
                count++;
                i++;
            }
            if (count > 1) {
                j += sprintf(&output[j], "%d", count);
                count = 1;
            }
        } 
        else {
            // Handle special characters
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0'; // Null-terminate the string
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character

    compressString(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}
