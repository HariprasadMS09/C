#include<stdio.h>

// Recursive function to print first n numbers
void printNumbers(int n) {
    if (n == 0) {
        return;
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int n = 7; // You can change this value to print first n numbers
    printf("First %d numbers: ", n);
    printNumbers(n);
    return 0;
}
