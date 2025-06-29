#include "list.h"
#include <stdlib.h>
#include <stdio.h>


List* create_list(){
	List* lt = (List *) malloc(sizeof(List));
	lt->size = 0;
	lt->head = NULL;

	return lt;
}//end create_list


Node* create_node(Student* st){
	Node* nd = (Node *) malloc(sizeof(Node));
	nd->data = st;
	nd->next = NULL;
	return nd;
}//end create_node()


void free_node(Node* node){
	free_student(node->data);
	free(node);
}//end free_node()


void free_list(List* lt){
	Node* aux = lt->head;

	while(aux != NULL){
		lt->head = lt->head->next;
		free_node(aux);
		aux = lt->head;
	}//end while

	free(lt);
}//end free_list()

int is_empty(List* lt){
	return lt->size == 0;
}//end is_empty()


void insert(List* lt, int pos, Student* st){
	if( pos < 0 || pos > lt->size){
		free_student(st);
		return;
	}

	Node* node = create_node(st);

	if( pos == 0 ){
		node->next = lt->head;
		lt->head = node;
	}else{
		Node* aux = lt->head;

		//parar em uma posição anterior
		for(int i = 0; i < pos-1; i++){
			aux = aux->next;
		}//end for i

		node->next = aux->next;
		aux->next = node;
	}//end if

	lt->size++;
}//end insert


void print_list(List* list){
	printf("List:\n");
	Node* aux = list->head;
	Student* st = NULL;

	while(aux != NULL){
		st = aux->data;
		print_student(st);
		aux = aux->next;
	}//end while

}//end print_list
