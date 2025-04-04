#include<stdio.h>
#include<string.h>

int main() {
    FILE *fptr;
    char str[100], ch;

    // Open the file in read mode
    fptr = fopen("Q1_text.txt", "r");
    if (fptr == NULL) {
        printf("Error: File cannot be opened.\n");
        return 1;
    }

    // Read characters from the file and store them in str
    int i = 0;
    while ((ch = fgetc(fptr)) != EOF) {
        str[i] = ch; // Store character in the array
        i++;
        if (i >= sizeof(str) - 1) { // Prevent overflow
            break;
        }
    }

    // Null-terminate the string
    str[i] = '\0';

    // Close the file
    fclose(fptr);

    fopen("Q1_text.txt", "w");

    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            count += 1;
        }
    }

    fprintf(fptr, "The number of vowels in the text = %d", count);

    fclose(fptr);
    return 0;
}
