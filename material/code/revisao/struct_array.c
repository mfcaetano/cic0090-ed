#include <stdio.h>

#define MAX_GRADES 3
#define MAX_STUDENTS 2

// Struct definition
typedef struct {
    char name[50];
    int age;
    float grades[MAX_GRADES];
} Student;

// Function signature
void print_student_info(const Student* s, int num_students);

// Function implementation
void print_student_info(const Student* s, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", s[i].name);
        printf("  Age: %d\n", s[i].age);
        printf("  Grades: ");
        for (int j = 0; j < MAX_GRADES; j++) {
            printf("%.2f ", s[i].grades[j]);
        }
        printf("\n");
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {"Alice", 20, {7.5, 8.0, 9.0}},
        {"Bob", 22, {6.0, 7.0, 8.5}}
    };

    print_student_info(students, MAX_STUDENTS);

    return 0;
}
