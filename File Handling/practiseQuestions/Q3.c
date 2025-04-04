#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char course[100];
    float cgpa;
} Student;

int main() {
    Student stu[5];
    int i;

    FILE *fptr;
    fptr = fopen("studentDetails.txt", "w");

    if (fptr == NULL) {
        printf("Error: Could not create or open the file.\n");
        return 1;
    }

    // Collect data for 5 students
    for (i = 0; i < 5; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Name: ");
        getchar(); // Clear input buffer
        fgets(stu[i].name, sizeof(stu[i].name), stdin);
        stu[i].name[strcspn(stu[i].name, "\n")] = 0; // Remove trailing newline

        printf("Course: ");
        fgets(stu[i].course, sizeof(stu[i].course), stdin);
        stu[i].course[strcspn(stu[i].course, "\n")] = 0; // Remove trailing newline

        printf("CGPA: ");
        scanf("%f", &stu[i].cgpa);
    }

    // Write data to the file in table format
    fprintf(fptr, " %-20s  %-15s  %-5s \n", "Name", "Course", "CGPA");
    fprintf(fptr, "-----------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        fprintf(fptr, " %-20s  %-15s  %-5.2f \n", stu[i].name, stu[i].course, stu[i].cgpa);
    }

    fclose(fptr);

    printf("Student details have been formatted and saved in 'studentDetails.txt'.\n");

    return 0;
}
