#include "stack.h"

/*
 * Cria uma pilha vazia.
 * Aloca memória e inicializa os campos topo e tamanho.
 */
Stack* create_stack(void) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para a pilha.\n");
        exit(EXIT_FAILURE);
    }
    stack->topo = NULL;
    stack->tamanho = 0;
    return stack;
}

/*
 * Libera todos os nós e depois a pilha.
 */
void free_stack(Stack* stack) {
    if (stack == NULL) return;

    No* atual = stack->topo;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }

    free(stack);
}

/*
 * Retorna 1 se a pilha estiver vazia, 0 caso contrário.
 */
int is_empty(Stack* stack) {
    return (stack == NULL || stack->tamanho == 0);
}

/*
 * Insere um novo valor no topo da pilha.
 */
void push(Stack* stack, int valor) {
    if (stack == NULL) return;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }

    novo->dado = valor;
    novo->prox = stack->topo;
    stack->topo = novo;
    stack->tamanho++;
}

/*
 * Remove o topo da pilha.
 * Retorna o valor via ponteiro e 1 se sucesso, 0 se vazia.
 */
int pop(Stack* stack, int* valor) {
    if (is_empty(stack)) {
        return 0;
    }

    No* aux = stack->topo;
    *valor = aux->dado;

    stack->topo = aux->prox;
    free(aux);
    stack->tamanho--;

    return 1;
}

/*
 * Retorna o valor do topo da pilha sem removê-lo.
 */
int peek(Stack* stack, int* valor) {
    if (is_empty(stack)) {
        return 0;
    }

    *valor = stack->topo->dado;
    return 1;
}

/*
 * Imprime a pilha no formato Topo -> Base.
 */
void print_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha (tamanho = %d)\n", stack->tamanho);
    printf("Topo -> ");

    No* atual = stack->topo;
    while (atual != NULL) {
        printf("[%d] ", atual->dado);
        atual = atual->prox;
    }

    printf("<- Base\n");
}

