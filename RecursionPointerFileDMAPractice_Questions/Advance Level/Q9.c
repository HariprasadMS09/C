//Write a program to encrypt and decrypt text read from a file using simple character substitution.
#include<stdio.h>
#include<stdlib.h>

#define maxSize 100
#define SHIFT 8

void encryptFile(const char *inputFile, const char *encryptedFile){
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(encryptedFile, "w");

    if(in == NULL || out == NULL){
        printf("Error: Cannot open file\n");
        exit (1);
    }

    char ch;
    while((ch = fgetc(in)) != EOF){
        fputc(ch + SHIFT, out);
    }

    fclose(in);
    fclose(out);
    printf("Encryption completed; Encrypted file saved in %s", encryptedFile);
}

void decryptFile(const char *encryptedFile, const char *decryptedFile){
    FILE *in = fopen(encryptedFile, "r");
    FILE *out = fopen(decryptedFile, "w");

    if(in == NULL || out == NULL){
        printf("Error: File cannont open\n");
        exit (1);
    }

    char ch;
    while((ch = fgetc(in)) != EOF){
        fputc(ch - SHIFT, out);
    }

    fclose(in);
    fclose(out);
    printf("Decryption completed; Decrypted file saved in %s", decryptedFile);
}

int main(){
    char inputFile[maxSize], encryptedFile[maxSize], decryptedFile[maxSize];

    printf("Enter the name of input file: ");
    scanf("%s", &inputFile);

    printf("Enter the name of encrypt file: ");
    scanf("%s", &encryptedFile);

    encryptFile(inputFile, encryptedFile);

    printf("Enter the name of decrypt file: ");
    scanf("%s", &decryptedFile);

    decryptFile(encryptedFile, decryptedFile);
    return 0;
}