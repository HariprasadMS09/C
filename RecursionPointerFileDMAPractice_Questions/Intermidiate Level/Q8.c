//Write a program to calculate the length of a string using pointers instead of array indexing.
#include <stdio.h>
#include <string.h>

#define maxLength 100

int main() {
    char txt[maxLength];
    int l = 0;
    char *sptr;

    printf("Enter the text (Max Length: %d):\n", maxLength);
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0'; // Remove the newline character

    sptr = txt;

    // Calculate length using pointer traversal
    while (*sptr != '\0') {
        l++;
        sptr++;
    }

    printf("Length of the entered text = %d\n", l);
    return 0;
}
