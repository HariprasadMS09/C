//Write a program to calculate the factorial of a number using recursion.
#include<stdio.h>

int findFactorial(int n){
    if(n == 1 || n == 0){
        return 1;
    }
    int fN = n * findFactorial(n-1);
    return fN;
}

int main(){
    int n, fact;

    printf("Enter a number: ");
    scanf("%d", &n);

    fact = findFactorial(n);

    printf("The factorial of number %d = %d", n, fact);
}