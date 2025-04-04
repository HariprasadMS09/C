#include <stdio.h>
#include <string.h>
#define maxSize 100

typedef struct studentDetails {
    char name[100];
    char grade;
    float marks;
} SD;

// Function to take details of students
void takeDetails(SD stu[], int n) {
    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d name: ", i + 1);
        getchar(); // To consume the newline character left by previous input
        fgets(stu[i].name, sizeof(stu[i].name), stdin);
        stu[i].name[strcspn(stu[i].name, "\n")] = 0; // Remove newline from name

        printf("Student %d marks: ", i + 1);
        scanf("%f", &stu[i].marks);

        printf("Student %d grade: ", i + 1);
        getchar(); // Consume the newline left by previous input
        scanf("%c", &stu[i].grade);
    }
}

// Function to display student details
void display(SD stu[], int n) {
    printf("|SL NO\t|NAME\t|MARKS\t|GRADE\n");
    for (int i = 0; i < n; i++) {
        printf("|%d\t|%s\t|%f\t|%c\n", i + 1, stu[i].name, stu[i].marks, stu[i].grade);
    }
}

// Function to sort students based on marks (ascending order)
void sort(SD stu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stu[j].marks < stu[j + 1].marks) {
                // Swap the entire structure
                SD temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

int main() {
    SD stu[maxSize];
    int n;

    printf("Enter the number of students in your class (max: %d): ", maxSize);
    scanf("%d", &n);

    takeDetails(stu, n);

    printf("\nStudent details before sorting:\n");
    display(stu, n);

    sort(stu, n);

    printf("\nStudent details after sorting (by marks):\n");
    display(stu, n);

    return 0;
}
