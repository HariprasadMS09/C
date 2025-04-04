#include<stdio.h>
#define maxSize 100

void main(){
    int arr[maxSize], i, j, n, key;

    printf("Enter array size (max : %d) : ", maxSize);
    scanf("%d", &n);

    printf("Enter array elements \n");
    for(i = 0; i < n ; i++){
        printf("[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array before insertion sort \n");
    for(i = 0; i < n ; i++){
        printf("%d\t", arr[i]);
    }

    for(i = 1; i < n ; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\nArray after insertion sort \n");
    for(i = 0; i < n ; i++){
        printf("%d\t", arr[i]);
    }

}