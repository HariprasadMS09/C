//Write a recursive program to calculate the factorial of a number or to solve the Tower of Hanoi problem.
#include<stdio.h>

int factorial(int num){
    if(num == 1){
        return 1;
    }
    int fNm1 = factorial(num-1);
    int fN = fNm1 * num;
    return fN;
}

int main(){
    int n, fact = 1;

    printf("Enter a number\n");
    scanf("%d", &n);

    fact = factorial(n);
    printf("The factorial of the given number %d = %d", n, fact);
}
