#include<stdio.h>
#define maxSize 100

void main(){
    int arr[maxSize], n, i, j, minIndex;

    printf("Enter the array size (max: %d) : ", maxSize);
    scanf("%d", &n);

    printf("Enter array elements \n");
    for(i=0; i<n; i++){
        printf("[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array elements before Selection sort \n");
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }

    for(i=0; i<n-1; i++){
        minIndex = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    printf("\nArray elements after Selection sort \n");
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}
