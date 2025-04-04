#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], txt[1000];

    // Input filename
    printf("Enter the filename in which you want to add text: \n");
    scanf("%s", filename);

    // Open file in append mode
    fptr = fopen(filename, "a");
    if (fptr == NULL) {
        printf("Error: Could not find or open file %s.\n", filename);
        return 1;
    }

    // Input text to append
    printf("Enter the text you need to add into the file %s: \n", filename);
    getchar(); // To clear the newline character left in the buffer
    fgets(txt, sizeof(txt), stdin);

    // Write to file
    fprintf(fptr, "%s", txt);

    // Close the file
    fclose(fptr);

    printf("File updated successfully.\n");
    return 0;
}
