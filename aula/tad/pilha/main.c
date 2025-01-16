#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  Stack* stack = create_stack();
  
//  printf("%lu\n", sizeof(stack));
//  printf("%lu\n", sizeof(stack->tamanho));
  
  for(int i = 0; i < 10; i++){
    push(stack, i+1);
  }
  
  
  printf(">>>> desempilhando: \n");
  Status s;
  for(int i = 0; i < 13; i++){
    s = pop(stack);
    
    if( s.status == TRUE){
      printf("Valor: %d \n", s.dado);
    }else if( s.status == FALSE){
      printf("Erro, pilha vazia!\n");
    }
  }
  
  //print_stack(stack);


  free_stack(stack);
}
