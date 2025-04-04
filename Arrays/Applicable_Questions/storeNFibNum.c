#include <stdio.h>

// Recursive function to calculate Fibonacci numbers and store them in an array
void generateFib(int n, int fibArr[]) {
    if (n == 0) {
        fibArr[0] = 0;
        return;
    }
    if (n == 1) {
        fibArr[0] = 0;
        fibArr[1] = 1;
        return;
    }

    // Recursive call for the previous terms
    generateFib(n - 1, fibArr);

    // Calculate the nth Fibonacci number
    fibArr[n] = fibArr[n - 1] + fibArr[n - 2];
}

int main() {
    int n = 10; // Number of terms in the Fibonacci sequence
    int fibArr[n + 1]; // Array to store Fibonacci numbers

    // Generate Fibonacci sequence using recursion
    generateFib(n, fibArr);

    // Print the Fibonacci sequence
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (int i = 0; i <= n; i++) {
        printf("%d\t", fibArr[i]);
    }

    return 0;
}
