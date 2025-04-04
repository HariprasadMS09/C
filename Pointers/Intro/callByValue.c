#include<stdio.h>
void square(int n){
    n = n*n;
    printf("Square of given number = %d \n", n);
}

int main(){
    int num = 10;
    square(num);
    printf("The given number is %d", num); //here the value of number doesn't changed because the absolute value doesn't changed
}