
#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct Node{
    int item;

    struct Node* next;
} Node;

typedef struct{
    Node* begin;
    Node* end;
    int size;
} Queue;

Queue* create_queue();

Node* create_node(int item);

void enqueue(Queue* q, int item);

int dequeue(Queue* q);

int front(Queue* q);

int is_empty(Queue* q);

void print_queue(Queue* q);

void free_queue(Queue* q);


#endif
