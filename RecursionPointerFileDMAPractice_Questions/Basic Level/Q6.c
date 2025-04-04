//Implement a recursive program to find the sum of digits of a given number.
#include<stdio.h>

int fingSumOfDigits(int n){
    if(n == 0){
        return 0;
    }
    return (n % 10) + fingSumOfDigits(n / 10);
}

int main(){
    int n, sum;
    printf("Enter the number: ");
    scanf("%d", &n);

    if (n < 0) {
        n = -n; // Convert to positive for calculation
    }

    sum = fingSumOfDigits(n);
    printf("The sum of digits of the number %d = %d", n, sum);
}
