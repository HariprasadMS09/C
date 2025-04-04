#include<stdio.h>
void even(int n){
    if(n == 0){
        return;
    }
    int r = n%2;
    if(r==0){
        even(n-2);
        printf("%d \n",n);
    }
    else{
        n = n-1;
        even(n-2);
        printf("%d \n",n);
    }
}

void main(){
    even(20);
}