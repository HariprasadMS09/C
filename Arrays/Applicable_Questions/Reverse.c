#include <stdio.h>

// Function to reverse an array
void reverse(int oldArr[], int n, int newArr[]) {
    for (int i = 0; i < n; i++) {
        newArr[i] = oldArr[n - i - 1]; // Copy elements in reverse order
    }
}

int main() {
    int oldArr[] = {1, 2, 3, 4, 5};
    int n = sizeof(oldArr) / sizeof(oldArr[0]); // Calculate the size of the array
    int newArr[n]; // Create a new array to hold reversed values

    // Call the reverse function
    reverse(oldArr, n, newArr);

    // Print the reversed array
    printf("Reversed Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", newArr[i]);
    }

    return 0;
}
