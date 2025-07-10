
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "graph.h"

typedef struct Queue_Node {
	Vertex* item;
	struct Queue_Node* next;
} Queue_Node;

typedef struct Queue{
	Queue_Node* begin;
	Queue_Node* end;
	int size;
} Queue;

Queue* create_queue();

Queue_Node* create_queue_node(Vertex* item);

void enqueue(Queue* q, Vertex* item);

Vertex* dequeue(Queue* q);

Vertex* front(Queue* q);

int is_empty(Queue* q);

void print_queue(Queue* q);

void free_queue(Queue* q);




#endif