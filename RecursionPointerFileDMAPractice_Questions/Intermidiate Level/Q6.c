//Write a program that appends user input to an existing file without overwriting it.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxLength 100

int main(){
    char fileName[maxLength], newTxt[maxLength];
    FILE *fptr;

    printf("Enter the file name to open\n");
    scanf("%s", &fileName);

    fptr = fopen(fileName, "a");
    if(fptr == NULL){
        printf("Error: Cannot open file in add mode\n");
        return 1;
    }
    printf("Enter the data which is to be added into the file(Max length: %d)\n", maxLength);
    getchar();
    fgets(newTxt, sizeof(newTxt), stdin);
    newTxt[strcspn(newTxt, "\n")] = '\0';

    fprintf(fptr, "%s", newTxt);

    printf("Data added successfully\n");

    fclose(fptr);
    return 0;
}
