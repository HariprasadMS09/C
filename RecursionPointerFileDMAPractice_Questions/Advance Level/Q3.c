//Create a program to merge the contents of two files into a third file.
#include <stdio.h>
#include <stdlib.h>

void mergeFiles(const char *file1, const char *file2, const char *outputFile) {
    FILE *fptr1, *fptr2, *fptrOut;
    char ch;

    // Open the first file in read mode
    fptr1 = fopen(file1, "r");
    if (fptr1 == NULL) {
        printf("Error: Could not open file %s\n", file1);
        exit(1);
    }

    // Open the second file in read mode
    fptr2 = fopen(file2, "r");
    if (fptr2 == NULL) {
        printf("Error: Could not open file %s\n", file2);
        fclose(fptr1); // Close the first file before exiting
        exit(1);
    }

    // Open the output file in write mode
    fptrOut = fopen(outputFile, "w");
    if (fptrOut == NULL) {
        printf("Error: Could not create output file %s\n", outputFile);
        fclose(fptr1);
        fclose(fptr2);
        exit(1);
    }

    // Copy contents of the first file to the output file
   while((ch = fgetc(fptr1)) != EOF){
        fputc(ch, fptrOut);
   }

    // Copy contents of the second file to the output file
    while ((ch = fgetc(fptr2)) != EOF) {
        fputc(ch, fptrOut);
    }

    printf("Files merged successfully into %s\n", outputFile);

    // Close all files
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptrOut);
}

int main() {
    char file1[100], file2[100], outputFile[100];

    // Input file names from the user
    printf("Enter the name of the first file: ");
    scanf("%s", file1);

    printf("Enter the name of the second file: ");
    scanf("%s", file2);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    // Call the function to merge files
    mergeFiles(file1, file2, outputFile);

    return 0;
}
