//Write a program to display the address of a variable using pointers.
#include<stdio.h>

int main(){
    int a = 2, *pa;

    pa = &a;
    printf("The memory address of a = %p", pa);

    return 0;
}
