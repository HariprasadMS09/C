//Write a program to demonstrate pointer arithmetic to access elements of an array.
#include<stdio.h>

int main(){
    int arr[] = {4, 6,44,33,2};
    int *aptr = &arr[0];
    int l = sizeof(arr) / sizeof(arr[0]);

    printf("Accessing array element using pointer arithmetic\n");
    for(int i = 0; i < l; i++){
        printf("arr[%d]: %d\n", i + 1 , *(aptr + i));
    }
    printf("\n");

    printf("Modifying array elements using pointer arithmetic...\n");
    for(int i = 0; i < l; i++){
        *(aptr + i) += 10;
    }
    printf("\n");

    printf("Final array contents\n");
    for(int i = 0; i < l; i++){
        printf("arr[%d]: %d\n", i + 1 , *(aptr + i));
    }

    return 0;
}
