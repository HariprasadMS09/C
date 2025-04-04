#include <stdio.h>

int main() {
    FILE *file;
    char filename[100], c;

    // Get the filename from the user
    printf("Enter the filename to open: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not find %s.\n", filename);
        return 1;
    }

    printf("File contents:\n");

    // Read and display file contents character by character
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    // Close the file
    fclose(file);

    return 0;
}
