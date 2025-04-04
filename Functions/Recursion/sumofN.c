#include<stdio.h>

//this is a recursion function
int sum(int n){
    if (n == 0){
        return 0;
    }
    int sumNm1 = sum(n-1); 
    int sumN = sumNm1 + n;
    return sumN;
}

int main(){
    printf("Sum = %d", sum(7));
    return 0;
}


