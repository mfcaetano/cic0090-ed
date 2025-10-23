#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Cria um novo nó com o valor informado
Node* create_node(int item) {
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro: falha ao alocar memória para o nó.\n");
        exit(1);
    }
    novo->item = item;
    novo->next = NULL;
    return novo;
}

// Cria uma nova fila vazia
Queue* create_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Erro: falha ao alocar memória para a fila.\n");
        exit(1);
    }
    q->begin = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
}

// Verifica se a fila está vazia
int is_empty(Queue* q) {
    return (q->size == 0);
}

// Adiciona um elemento ao final da fila
void enqueue(Queue* q, int item) {
    Node* novo = create_node(item);
    if (is_empty(q)) {
        q->begin = novo;
        q->end = novo;
    } else {
        q->end->next = novo;
        q->end = novo;
    }
    q->size++;
}

// Remove o elemento do início da fila e retorna seu valor
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Erro: a fila está vazia.\n");
        return -1;
    }
    Node* temp = q->begin;
    int valor = temp->item;
    q->begin = q->begin->next;
    free(temp);
    q->size--;
    if (q->begin == NULL) q->end = NULL;
    return valor;
}

// Retorna o elemento do início sem removê-lo
int front(Queue* q) {
    if (is_empty(q)) {
        printf("Fila vazia.\n");
        return -1;
    }
    return q->begin->item;
}

// Imprime todos os elementos da fila
void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Fila vazia.\n");
        return;
    }
    Node* atual = q->begin;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->item);
        atual = atual->next;
    }
    printf("\n");
}

// Libera toda a memória alocada pela fila
void free_queue(Queue* q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
    printf("Fila liberada da memória.\n");
}
