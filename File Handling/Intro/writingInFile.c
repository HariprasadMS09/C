#include <stdio.h>

int main() {
    FILE *fptr;
    char filename[100], txt[10000];

    // Ask user for filename
    printf("Enter the filename to open: ");
    scanf("%s", filename); 

    // Open the file for writing
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error: Cannot create or open the file.\n");
        return 1;
    }

    // Ask user for the text to write into the file
    printf("Enter the text you want to write inside the file:\n");
    getchar(); // Clear newline character left by scanf
    fgets(txt, sizeof(txt), stdin); // Safer than scanf for strings

    // Write the text to the file
    fprintf(fptr, "%s", txt);

    // Close the file
    fclose(fptr);

    printf("File written successfully.\n");
    return 0;
}
