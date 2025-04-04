//Use recursion to calculate the nth Fibonacci number.

#include<stdio.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    int fibNm1 = fibonacci(n-1);
    int fibNm2 = fibonacci(n-2);
    int fibN = fibNm1 + fibNm2;
    //printf("Fib of %d = %d \n", n, fibN); run this if u want all levels
    return fibN;
}

int main(){
    int n;
    printf("Enter the number to find fib: ");
    scanf("%d", &n);

    int fibN = fibonacci(n);
    printf("The n^th fib value is = %d", fibN);
    return 0;
}