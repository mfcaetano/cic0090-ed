#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack* create_stack(){
  Stack* stack = (Stack *) malloc(sizeof(Stack));
  
  stack->topo = NULL;
  stack->tamanho = 0;
  //(*stack).tamanho = 0;
  
  return stack;
}//end create_stack()

void free_stack(Stack* stack){
  No* aux = stack->topo;
  
  while( aux != NULL ){
    stack->topo = stack->topo->prox;
    free(aux);
    //aux = aux->prox; - errado pois aux foi liberado
    aux = stack->topo;
  }
  
  free(stack);
}//end free_stack()

No* create_no(int dado){
  No* no = (No *) malloc(sizeof(No));
  
  no->prox = NULL;
  no->dado = dado;

  return no;
}//end create_no

void push(Stack* stack, int item){
  No* no = create_no(item);
  
  no->prox = stack->topo;
  stack->topo = no;
  stack->tamanho++;
  
}//end push()

Status pop(Stack* stack){
  Status retorno;
  
  if(stack->tamanho == 0){
    retorno.status = FALSE;
    return retorno;
  }
  
  retorno.dado = stack->topo->dado;
  retorno.status = TRUE;
  No* aux = stack->topo;
  stack->topo = stack->topo->prox;
  free(aux);
  stack->tamanho--;
  return retorno;
}//end pop()

int peak(Stack* stack){
}//end peak();

int is_empty(Stack* stack){
}//end is_empty()

void print_stack(Stack* stack){
  No* no = stack->topo;
  
  printf("Stack:\n");
  while(no != NULL){
    printf("%d \n", no->dado);
    no = no->prox;
  }
  printf("\n");
  
}//end print_stack()


