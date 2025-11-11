#ifndef __STACK_H__
#define __STACK_H__

typedef struct no {
    int dado;
    struct no* proximo;
} No;

typedef struct pilha {
  No* topo;
  int tamanho;
} Pilha;


Pilha* cria_pilha(void);

No* cria_no(int valor);

void free_pilha(Pilha* pilha);

int is_empty(Pilha* pilha);

void push(Pilha* pilha, int valor);

int pop(Pilha* pilha, int* valor);

int peek(Pilha* pilha, int* valor);




#endif
