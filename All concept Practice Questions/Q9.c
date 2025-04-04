//Write a program to read and write a file, appending additional information to it.
#include<stdio.h>
void main(){
    FILE *fptr;

    fptr = fopen("test.txt", "w");
    fprintf(fptr,"%s", "Hi there!\n");

    fclose(fptr);

    fptr = fopen("test.txt", "r");
    fclose(fptr);

    fptr = fopen("test.txt", "a");
    fprintf(fptr, "%s", "How r u");
    fclose(fptr);
}