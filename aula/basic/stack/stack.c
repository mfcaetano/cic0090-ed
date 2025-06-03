#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* create_stack(){
  Stack* stack = (Stack *) malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  
  return stack;
}//end create_stack();


void free_stack(Stack* stack){
  Node* pt_aux = stack->top;

  while(pt_aux){
    stack->top = stack->top->next;
    
    free_node(pt_aux);
    
    pt_aux = stack->top;
  }//end while

  free(stack);
}//end free_stack()

Node* create_node(Student* item){
  Node* node = (Node *) malloc(sizeof(Node));
  node->item = item;
  node->next = NULL;
  
  return node;
}//end create_node()

void free_node(Node* node){
    free_student(node->item);
    free(node);   
}//end free_node()

//empilhar um aluno na pilha
void push(Stack* stack, Student* item){
  Node* node = create_node(item);
  
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}//end push()

//desempilhar um aluno
Student* pop(Stack* stack){
  if(stack->size == 0)
    return NULL;
  
  Student* pt_student = stack->top->item;
  Node* pt_aux = stack->top;
  stack->top = stack->top->next;
  stack->size--;
  
  free(pt_aux);
  return pt_student;
}

//retornar o elemento do topo da pilha sem desempilhar
Student* peak(Stack* stack){
}

//verificar se a pilha está vazia
int is_empty(Stack* stack){
}

//imprime a estrutura do tipo pilha
void print_stack(Stack* stack){
}
