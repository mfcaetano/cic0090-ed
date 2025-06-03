
#ifndef __STUDENT_H__
#define __STUDENT_H__

typedef struct {
  char* name;
  int age;
} Student;


Student* create_student(const char* name, int age);
void free_student(Student* student);
void print_student(Student* student);

#endif
