//program to perform insertion, deletion, and searching in an array.

#include <stdio.h>

#define MAX_SIZE 100

// Function to display the array
void display(int arr[], int n) {
    if (n == 0) {
        printf("The array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into the array
int insert(int arr[], int n, int element, int position) {
    if (n >= MAX_SIZE) {
        printf("Error: Array is full. Cannot insert.\n");
        return n;
    }

    if (position < 1 || position > n + 1) {
        printf("Error: Invalid position.\n");
        return n;
    }

    // Shift elements to the right
    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element
    arr[position - 1] = element;

    printf("Element inserted successfully.\n");
    return n + 1; // Increase the size of the array
}

// Function to delete an element from the array
int delete(int arr[], int n, int position) {
    if (n == 0) {
        printf("Error: Array is empty. Cannot delete.\n");
        return n;
    }

    if (position < 1 || position > n) {
        printf("Error: Invalid position.\n");
        return n;
    }

    // Shift elements to the left
    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully.\n");
    return n - 1; // Decrease the size of the array
}

// Function to search for an element in the array
void search(int arr[], int n, int element) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            printf("Element %d found at position %d.\n", element, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", element);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current size of the array
    int choice, element, position;

    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Insertion
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position to insert (1 to %d): ", n + 1);
            scanf("%d", &position);
            n = insert(arr, n, element, position);
            break;

        case 2: // Deletion
            printf("Enter the position to delete (1 to %d): ", n);
            scanf("%d", &position);
            n = delete(arr, n, position);
            break;

        case 3: // Searching
            printf("Enter the element to search: ");
            scanf("%d", &element);
            search(arr, n, element);
            break;

        case 4: // Display
            display(arr, n);
            break;

        case 5: // Exit
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
