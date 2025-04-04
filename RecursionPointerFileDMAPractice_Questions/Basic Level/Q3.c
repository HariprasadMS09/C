//Write a program to demonstrate the use of pointers by swapping two numbers.
#include<stdio.h>

int main() {
    int x = 10, y = 20, temp;
    int *px, *py;

    // Initialize pointers to point to the addresses of x and y
    px = &x;
    py = &y;

    // Print values before swapping
    printf("Before swapping a = %d\tb = %d\n", *px, *py);

    // Swap the values using pointers
    temp = *px;
    *px = *py;
    *py = temp;

    // Print values after swapping
    printf("After swapping a = %d\tb = %d\n", *px, *py);

    return 0;
}
