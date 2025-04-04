#include<stdio.h>

void countEven(int newArr[], int n){
    for(int i=0; i<n; i++){
        if(newArr[i]%2 == 0){
            printf("%d \t", newArr[i]);
        }
    }
}

int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countEven(arr,n);
}