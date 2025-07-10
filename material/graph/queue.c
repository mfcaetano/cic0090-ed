#include "queue.h"
#include <stdlib.h>
#include <stdio.h>


Queue* create_queue(){
	Queue* queue = (Queue *) malloc(sizeof(Queue));
	queue->begin = NULL;
	queue->end = NULL;
	queue->size = 0;

	return queue;
}//end create_queue()


Queue_Node* create_queue_node(Vertex* item){
	Queue_Node* node = (Queue_Node *) malloc(sizeof(Queue_Node));
	node->next = NULL;
	node->item = item;
	return node;
}//end create_Queue_Node()


void enqueue(Queue* q, Vertex* item){
	Queue_Node* node = create_queue_node(item);

	if ( q->end != NULL ){
		q->end->next = node;
	}else{
		q->begin = node;
	}

	q->end = node;
	q->size++;
}//end enqueue()


Vertex* dequeue(Queue* q){
	if( q->begin == NULL )
		return 0;

	Queue_Node* aux = q->begin;
	Vertex* item = aux->item;

	q->begin = q->begin->next;
	free(aux);
	q->size--;

	if(is_empty(q))
		q->end = NULL;

	return item;
}//end dequeue()


Vertex* front(Queue* q){
	if( q->begin == NULL )
		return NULL;

	return q->begin->item;
}//end front()


int is_empty(Queue* q){
	return q->size == 0;
}//end is_empty()


void print_queue(Queue* q){
	Queue_Node* aux = q->begin;
	printf("Queue: ");

	while( aux != NULL){
		printf("%d ", aux->item->id);
		aux = aux->next;
	}
	printf("\n");

}//end print_queue()

void free_queue(Queue* q){
	Queue_Node* aux = q->begin;
	Queue_Node* f = aux;

	while( aux != NULL){
		aux = aux->next; 
		free(f);
		f = aux;
	}

	free(q);
}