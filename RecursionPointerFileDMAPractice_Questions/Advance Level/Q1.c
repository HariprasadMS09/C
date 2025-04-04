//Implement a recursive function to generate all permutations of a string.
#include <stdio.h>
#include <string.h>

// Swap characters at position i and j in a string
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void generatePermutations(char *str, int start, int end) {
    if (start == end) {
        printf("%s\n", str); // Print the current permutation
        return;
    }

    for (int i = start; i <= end; i++) {
        // Swap the current index with the start
        swap(&str[start], &str[i]);

        // Recursively call for the rest of the string
        generatePermutations(str, start + 1, end);

        // Backtrack to restore the original string
        swap(&str[start], &str[i]);
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string to generate its permutations: ");
    scanf("%s", str);

    int n = strlen(str);

    printf("Permutations of the string are:\n");
    generatePermutations(str, 0, n - 1);

    return 0;
}
