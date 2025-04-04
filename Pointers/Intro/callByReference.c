#include<stdio.h>
int square(int *n){
    *n = (*n) * (*n);
    printf("Square of given number = %d \n", *n);
}

int main(){
    int num = 10;
    square(&num);
    printf("Number is %d", num); //here the value of number changed because the absolute value is also changed
    return 0;
}