#include<stdio.h>
int factorial(int n){
    if(n == 1){
        return 1;
    }
    int inc_ans = factorial(n-1);
    int ans = inc_ans*n;
    return ans;
}

int main(){
    int fact = factorial(2);
    printf("Factorial of the given number = %d",fact);
    return 0;
}