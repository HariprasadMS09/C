#include<stdio.h>
void odd(int n){
    if(n <= 0){
        return;
    }
    int r = n%2;
    if(r==1){
        odd(n-2);
        printf("%d \n",n);
    }
    else{
        n = n-1;
        odd(n-2);
        printf("%d \n",n);
    }
}

void main(){
    odd(20);
}