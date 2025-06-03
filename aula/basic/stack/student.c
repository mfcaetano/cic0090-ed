#include "student.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Student* create_student(const char* name, int age){
  Student* pt_st = (Student *) malloc(sizeof(Student));
  
  //testar para ver se alocou de forma correta
  
  pt_st->age = age;
  
  pt_st->name = (char *) malloc((strlen(name)+1)*sizeof(char));
  strcpy(pt_st->name, name);

  return pt_st;
}//end create_student()

void free_student(Student* student){
  free(student->name);
  free(student);
}//end free_student()


void print_student(Student* student){
  printf("> %s - %d \n", student->name, student->age);
}
