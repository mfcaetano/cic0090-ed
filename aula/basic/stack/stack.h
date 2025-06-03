
#ifndef __STACK_H__
#define __STACK_H__

#include "student.h"

typedef struct Node {
  Student* item;
  struct Node* next;
} Node;

typedef struct{
  Node* top;
  int size;
} Stack;

Stack* create_stack();
void free_stack(Stack* stack);

Node* create_node(Student* item);
void free_node(Node* node);

//empilhar um aluno na pilha
void push(Stack* stack, Student* item);

//desempilhar um aluno
Student* pop(Stack* stack);

//retornar o elemento do topo da pilha sem desempilhar
Student* peak(Stack* stack);

//verificar se a pilha está vazia
int is_empty(Stack* stack);

//imprime a estrutura do tipo pilha
void print_stack(Stack* stack);






#endif


