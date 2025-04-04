#include<stdio.h>
int main(){
    FILE *fptr;
    char ch;

    fptr = fopen("Q1_text.txt", "r");
   
    while ((ch = fgetc(fptr)) != EOF) {
        printf("%c",ch);
    }

    fclose(fptr);
    return 0;
}