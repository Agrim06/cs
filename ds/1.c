#include <stdio.h>
#include <stdlib.h>


struct Student {
    char name[50];
    int reg_no;
    float marks[3];
    float avg_marks;
};


void readStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Reg No: ");
        scanf("%d", &s[i].reg_no);
        printf("Enter marks of 3 tests: ");
        for (int j = 0; j < 3; j++)
            scanf("%f", &s[i].marks[j]);
        s[i].avg_marks = 0;
    }
}
void displayStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Reg No: %d\n", s[i].reg_no);
        printf("Marks: %.2f %.2f %.2f\n",
               s[i].marks[0], s[i].marks[1], s[i].marks[2]);
        printf("Average Marks: %.2f\n", s[i].avg_marks);
    }
}
void calculateAverage(struct Student *s, int n) {
    float a, b, c;

    for (int i = 0; i < n; i++) {
        a = s[i].marks[0];
        b = s[i].marks[1];
        c = s[i].marks[2];

        if (a <= b && a <= c)
            s[i].avg_marks = (b + c) / 2;
        else if (b <= a && b <= c)
            s[i].avg_marks = (a + c) / 2;
        else
            s[i].avg_marks = (a + b) / 2;
    }
}
void sortByRegNo(struct Student *s, int n) {
    struct Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].reg_no > s[j + 1].reg_no) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student *students;
    int n, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);
    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do {
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. Read Student Information\n");
        printf("2. Display Student Information\n");
        printf("3. Calculate Average of Best Two Tests\n");
        printf("4. Sort Students by Reg_No\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readStudents(students, n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                calculateAverage(students, n);
                printf("Average calculated successfully.\n");
                break;
            case 4:
                sortByRegNo(students, n);
                printf("Students sorted by Reg_No.\n");
                break;
            case 0:
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    free(students);
    return 0;
}
