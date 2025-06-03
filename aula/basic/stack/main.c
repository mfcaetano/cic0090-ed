
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "student.h"

int main(){

  char nome[200];
  int idade;
  Student *pt_student;
  
  printf("Informe seu nome:\n");
  scanf("%[^\n]s", nome);
  printf("Informe sua idade: \n");
  scanf("%d", &idade);
  
  //print_student(pt_student);
  
  
  //free_student(pt_student);
  
  Stack* stack = create_stack();
  pt_student = create_student(nome, idade);

  
  push(stack, pt_student);
  
  
  //pt_aux = pop(stack);
  
  
  free_stack(stack);
}//end main()
