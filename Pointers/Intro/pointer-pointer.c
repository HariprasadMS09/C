#include<stdio.h>
void main(){
    int a = 0;
    int *p = &a;
    int **ptp = &p;
    printf("Value of a = %d \n", a);
    printf("Address of a = %p \n", &a); //u can also use 'p' instead of p here
    printf("Address of *p = %p \n", &p); //u can also use 'ptp' instead of ptp here
    printf("Value of address inside *p = %d \n", *p);
    printf("Address of **p = %p \n", &p); //u can also use 'ptp' instead of ptp here
    printf("Value of address of address inside **ptp = %d \n", **ptp);
}