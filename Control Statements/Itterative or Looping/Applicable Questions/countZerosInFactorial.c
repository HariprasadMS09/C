#include<stdio.h>

int findFact(int n){
    if(n == 1){
        return 1;
    }
    int factNm1 = findFact(n-1);
    int fact = factNm1 * n;
    return fact;
}

int countZeros(int factNo){
    int count = 0;
    while(factNo > 0){
        if(factNo % 10 == 0){
            count++;
        }
        factNo = factNo/10;
    }
    return count;
}

int main(){
    int num = 10;
    int factorial = findFact(num);
    int zeroCount = countZeros(factorial);
    printf("The factorial of the given number %d is = %d \n", num, factorial);
    printf("Number of zeros in %d are = %d", factorial, zeroCount);
    return 0;
}