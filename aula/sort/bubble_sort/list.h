

#ifndef __LIST_H__
#define __LIST_H__

#include "student.h"

typedef struct Node{
	Student* data;
	struct Node* next;
} Node;

typedef struct List{
	Node* head;
	int size;
} List;

List* create_list();
Node* create_node(Student* st);

void insert(List* lt, int pos, Student* st);

int is_empty(List* lt);


void print_list(List* list);

void free_node(Node* node);
void free_list(List* lt);


#endif
