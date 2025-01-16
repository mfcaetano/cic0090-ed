
#ifndef __STACK_H__
#define  __STACK_H__

#define TRUE 1
#define FALSE 0

typedef struct Status{
  int dado;
  int status; //0 False e 1 True
} Status;

typedef struct No{
  int dado;
  struct No* prox;
} No;

typedef struct Stack {
  No* topo;
  int tamanho;
} Stack;

Stack* create_stack();
void free_stack(Stack* stack);

No* create_no(int dado);

void push(Stack* stack, int item);

Status pop(Stack* stack);

int peak(Stack* stack);

int is_empty(Stack* stack);

void print_stack(Stack* stack);

#endif
