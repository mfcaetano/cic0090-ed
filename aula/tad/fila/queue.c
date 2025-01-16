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


Node* create_node(int item){
	Node* node = (Node *) malloc(sizeof(Node));
	node->next = NULL;
	node->item = item;
	return node;
}//end create_node()


void enqueue(Queue* q, int item){
	Node* node = create_node(item);

	if ( q->end != NULL ){
		q->end->next = node;
	}else{
		q->begin = node;
	}

	q->end = node;
	q->size++;
}//end enqueue()


int dequeue(Queue* q){
	if( q->begin == NULL )
		return 0;

	Node* aux = q->begin;
	int item = aux->item;

	q->begin = q->begin->next;
	free(aux);
	q->size--;

	return item;
}//end dequeue()


int front(Queue* q){

}//end front()


int is_empty(Queue* q){

}//end is_empty()


void print_queue(Queue* q){
	Node* aux = q->begin;
	printf("Queue: ");

	while( aux != NULL){
		printf("%d ", aux->item);
		aux = aux->next;
	}
	printf("\n");

}//end print_queue()

void free_queue(Queue* q){
	Node* aux = q->begin;
	Node* f = aux;

	while( aux != NULL){
		aux = aux->next; 
		free(f);
		f = aux;
	}

	free(q);
}