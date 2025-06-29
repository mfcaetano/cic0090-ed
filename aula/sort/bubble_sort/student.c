#include "student.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Student* create_student(const char* name, const int age, const char* cpf){
	Student* st = (Student *) malloc(sizeof(Student));

	st->name = (char *) malloc(strlen(name)+1);
	strcpy(st->name, name);

	st->age = age;

	st->cpf = (char *) malloc(strlen(cpf)+1);
	strcpy(st->cpf, cpf);

	return st;
}//end create_student()

void print_student(Student* st){
	printf("%s, %d, %s\n", st->name, st->age, st->cpf);
}//end print_student()

void free_student(Student* st){
	free(st->name);
	free(st->cpf);
	free(st);
}//end free_student()