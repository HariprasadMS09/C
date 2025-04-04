#include<stdio.h>
void main(){
    int a = 0;
    int *p = &a;
    printf("Value of a = %d \n", a);
    printf("Address of a = %p \n", p); //u can also use '&a' instead od p here 
    printf("The value stored inside pointer = %d", *p);
}