#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/*
 * Estrutura de nó da pilha.
 * Cada nó guarda um valor inteiro e um ponteiro para o próximo nó.
 */
typedef struct No {
    int dado;
    struct No* prox;
} No;

/*
 * Estrutura da pilha.
 * Guarda o ponteiro para o topo e o número de elementos.
 */
typedef struct {
    No* topo;
    int tamanho;
} Stack;

/*
 * Cria uma nova pilha vazia.
 * Retorna o ponteiro para a pilha criada.
 */
Stack* create_stack(void);

/*
 * Libera toda a memória alocada pela pilha.
 */
void free_stack(Stack* stack);

/*
 * Retorna 1 se a pilha estiver vazia, 0 caso contrário.
 */
int is_empty(Stack* stack);

/*
 * Insere um novo elemento no topo da pilha.
 */
void push(Stack* stack, int valor);

/*
 * Remove o elemento do topo da pilha e o retorna via ponteiro.
 * Retorna 1 se sucesso, 0 se a pilha estiver vazia.
 */
int pop(Stack* stack, int* valor);

/*
 * Retorna o valor do topo da pilha sem removê-lo.
 * Retorna 1 se sucesso, 0 se a pilha estiver vazia.
 */
int peek(Stack* stack, int* valor);

/*
 * Imprime todos os elementos da pilha.
 */
void print_stack(Stack* stack);

#endif

