//Sum of digits of numbers

#include<stdio.h>

// Function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    if (n == 0) {
        return 0; // Base case: no more digits to add
    }
    return (n % 10) + sumOfDigits(n / 10); // Add last digit to the sum of remaining digits
}

int main() {
    int number;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &number);

    // Handle negative numbers
    if (number < 0) {
        number = -number; // Convert to positive for calculation
    }

    // Get the sum of digits and print it
    int result = sumOfDigits(number);
    printf("The sum of digits of %d is: %d\n", number, result);

    return 0;
}
