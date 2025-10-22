#include "queue.h"
#include <stdlib.h>

Queue * create_queue(){
    Queue* q = (Queue *) malloc(sizeof(Queue));
    
    if(q == NULL){
        printf("Error: falha ao alocar memória para a fila. \n");
        exit(1);
    }
    
    q->begin = NULL;
    q->end = NULL;
    q->size = 0;
    
    return q;
}//end create_queue()

Node* create_node(int item){
    Node* node = (Node *) malloc(sizeof(Node));
    
    if( node == NULL){
        printf("Não foi possível alocar memória para nó!\n");
        exit(1);
    }
    
    node->item = item;
    node->next = NULL;
    
    return node;
}//end create_node()

void enqueue(Queue* q, int item){
    Node* node = create_node(item);
    
    if(is_empty(q)){
        q->begin = node;
        q->end = node;
    }else {
      q->end->next = node;
      q->end = node;
    }
    
    q->size++;
}//end enqueue()

int dequeue(Queue* q){
    if (is_empty(q)){
        printf("Fila vazia. \n");
        exit(1);
    }
    
    Node* aux = q->begin;
    int valor = aux->item;
    q->begin = q->begin->next;
    
    free(aux);
    q->size--;
    
    if (q->begin == NULL)
        q->end = NULL;
    
    return valor;
}

int front(Queue* q){
}

void print_queue(Queue* q){
}

void free_queue(Queue* q){
}

int is_empty(Queue* q){
  return (q->size == 0);
}//end is_empty()
