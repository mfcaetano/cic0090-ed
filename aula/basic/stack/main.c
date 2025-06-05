
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "student.h"

int main(){

  char nome[200];
  int idade;
  Student *pt_student;
  Stack* stack = create_stack();
  
  for(int i = 0; i < 3; i++){
  
    printf("Nome aluno %d:\n", i+1);
    scanf("%[^\n]s", nome);
    printf("Idade aluno %d:\n", i+1);
    scanf("%d", &idade);
    getchar();
    
    push(stack, create_student(nome, idade));
    
  }//end for i
  
  //print_student(pt_student);
  
  for(int i = 0; i < 3; i++){
    pt_student = pop(stack);
    print_student(pt_student);
   
    free_student(pt_student);
  }
  
  free_stack(stack);
}//end main()
