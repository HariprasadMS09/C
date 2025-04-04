//Create a simple CRUD (Create, Read, Update, Delete) application using file handling to manage student records.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

// Function to create a new student record
void createStudent() {
    FILE *file;
    fopen(FILENAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    getchar(); // Clear newline left by previous input
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter student age: ");
    scanf("%d", &student.age);

    fprintf(file, "%d,%s,%d\n", student.id, student.name, student.age);
    fclose(file);

    printf("Student record added successfully!\n");
}

// Function to read and display all student records
void readStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    Student student;
    printf("\nID\tName\t\tAge\n");
    printf("-----------------------------\n");

    while (fscanf(file, "%d,%49[^,],%d\n", &student.id, student.name, &student.age) == 3) {
        printf("%d\t%-15s\t%d\n", student.id, student.name, student.age);
    }

    fclose(file);
}

// Function to update a student record by ID
void updateStudent() {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    int id, found = 0;
    Student student;
    printf("Enter the ID of the student to update: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%49[^,],%d\n", &student.id, student.name, &student.age) == 3) {
        if (student.id == id) {
            found = 1;
            printf("Enter new name: ");
            getchar(); // Clear newline
            fgets(student.name, sizeof(student.name), stdin);
            student.name[strcspn(student.name, "\n")] = '\0';
            printf("Enter new age: ");
            scanf("%d", &student.age);
        }
        fprintf(temp, "%d,%s,%d\n", student.id, student.name, student.age);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Student record updated successfully!\n");
    } else {
        remove("temp.txt");
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to delete a student record by ID
void deleteStudent() {
    FILE *file = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    int id, found = 0;
    Student student;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%49[^,],%d\n", &student.id, student.name, &student.age) == 3) {
        if (student.id == id) {
            found = 1;
            continue; // Skip writing the student to the temp file
        }
        fprintf(temp, "%d,%s,%d\n", student.id, student.name, student.age);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("Student record deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("Student with ID %d not found.\n", id);
    }
}

// Main menu for the CRUD application
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Records CRUD Application ---\n");
        printf("1. Create Student\n");
        printf("2. Read Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createStudent();
                break;
            case 2:
                readStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}