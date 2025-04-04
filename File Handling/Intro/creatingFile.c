#include<stdio.h>

int main(){
    FILE *fptr;
    char filename[100];

    // printf("Enter the filename to create \n");
    // scanf("%s", filename);

    if(fptr == NULL){
        printf("Error : Can't find file");
    }
    fopen("test.txt","w");
    fclose(fptr);
    printf("File created successfully");
    return 0;
}
