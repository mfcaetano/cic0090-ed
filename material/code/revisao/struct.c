#include <stdio.h>

// Struct definition
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

// Function signature
void update_student(Student* s);

// Function implementation
void update_student(Student* s) {
    s->age += 1;
    s->grade += 0.5;
}

int main() {
    Student student = {"Alice", 20, 7.5};

    update_student(&student);  // Pass struct by reference

    printf("name = %s, age = %d, grade = %.2f\n", student.name, student.age, student.grade);

    return 0;
}
