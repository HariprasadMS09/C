#include<stdio.h>
void main(){
    int n = 10;
    int* p = &n;
    *p = 34; //by * we can access the value stord inside the address
    printf("n = %d", n);
}