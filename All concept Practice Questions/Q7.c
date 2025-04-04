//Generate all prime numbers up to N using the Sieve of Eratosthenes.
#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    if (n < 2) {
        printf("No prime numbers up to %d.\n", n);
        return;
    }

    bool isPrime[n + 1]; // Create an array to mark prime numbers
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true; // Initialize all numbers as prime
    }

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Perform the sieve
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // Mark multiples of i as not prime
            }
        }
    }

    // Print the prime numbers
    printf("Prime numbers up to %d:\n", n);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the value of N: ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);

    return 0;
}
