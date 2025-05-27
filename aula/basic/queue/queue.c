
#include <stdlib.h>
#include "queue.h"

Queue* create_queue(){
    Queue* queue = (Queue *) malloc(sizeof(Queue));

    queue->begin = NULL;
    queue->end = NULL;
    queue->size = 0;

    return queue;
}

Node* create_node(int item){
    Node* node = (Node *) malloc(sizeof(Node));

    node->item = item;
    node->next = NULL;

    return node;
}

void enqueue(Queue* q, int item){
    Node* node = create_node(item);

    if(q->end != NULL)
        q->end->next = node;
    else
        q->begin = node;

    q->end = node;
    q->size++;
}

int dequeue(Queue* q){
    if( q->begin == NULL )
        exit(0);

    Node* aux = q->begin;
    int item = aux->item;

    q->begin = q->begin->next;
    free(aux);
    return item;
}

int front(Queue* q){
}

int is_empty(Queue* q){
}

void print_queue(Queue* q){
}

void free_queue(Queue* q){
}

