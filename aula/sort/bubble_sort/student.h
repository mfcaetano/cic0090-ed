
#ifndef __STUDENT_H__
#define __STUDENT_H__

typedef struct Student {
	char* name;
	int age;
	char* cpf;
} Student;

Student* create_student(const char* name, const int age, const char* cpf);

void print_student(Student* st);

void free_student(Student* st);




#endif