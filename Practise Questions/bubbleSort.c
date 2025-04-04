#include <stdio.h>
#define maxSize 100

int main() {
    int arr[maxSize], n;

    printf("Enter the array size (max: %d): ", maxSize);
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array before Bubble sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; i++) { // Loop for passes
        for (int j = 0; j < n - i - 1; j++) { // Loop for comparisons
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Array after Bubble sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}
