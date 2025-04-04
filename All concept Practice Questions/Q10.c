//Create a program that uses malloc and calloc to allocate memory dynamically for a list of integers. Allow the user to add, remove, and modify elements.
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int size) {
    if (size == 0) {
        printf("The list is empty.\n");
        return;
    }

    printf("Current list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL; // Pointer to hold the dynamic array
    int size = 0, capacity = 0, choice, value, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an element\n");
        printf("2. Remove an element\n");
        printf("3. Modify an element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Add an element
            printf("Enter the value to add: ");
            scanf("%d", &value);

            // Resize the array if needed
            if (size == capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2; // Double capacity
                arr = realloc(arr, capacity * sizeof(int));
                if (!arr) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
            }

            arr[size++] = value; // Add the value
            printf("Element added.\n");
            break;

        case 2: // Remove an element
            if (size == 0) {
                printf("The list is empty. Nothing to remove.\n");
                break;
            }

            printf("Enter the position to remove (1 to %d): ", size);
            scanf("%d", &position);

            if (position < 1 || position > size) {
                printf("Invalid position.\n");
                break;
            }

            // Shift elements to the left
            for (int i = position - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--; // Decrease the size
            printf("Element removed.\n");
            break;

        case 3: // Modify an element
            if (size == 0) {
                printf("The list is empty. Nothing to modify.\n");
                break;
            }

            printf("Enter the position to modify (1 to %d): ", size);
            scanf("%d", &position);

            if (position < 1 || position > size) {
                printf("Invalid position.\n");
                break;
            }

            printf("Enter the new value: ");
            scanf("%d", &value);
            arr[position - 1] = value;
            printf("Element modified.\n");
            break;

        case 4: // Display the list
            display(arr, size);
            break;

        case 5: // Exit
            free(arr); // Free the allocated memory
            printf("Exiting the program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
