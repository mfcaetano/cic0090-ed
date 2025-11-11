#include "sort.h"
#include <string.h>
#include <stdio.h>

void bubble_sort(List* lt, int (*sort_key)(Student* st1, Student* st2) ){
	Node* p_aux = NULL;
	Student* p_st = NULL;
	int result;

	if(is_empty(lt))
		return;

	for(int i = 0; i < lt->size-1; i++){
		p_aux = lt->head;

		for(int j = 0; j < lt->size-1-i; j++){
			result = sort_key(p_aux->data, p_aux->next->data);

			if(result > 0){
				p_st = p_aux->data; 
				p_aux->data = p_aux->next->data;
				p_aux->next->data = p_st;
			}//end if

			p_aux = p_aux->next;

		}//end for j
	}//end for i

}//end bubble_sort()

int name_key(Student* st1, Student* st2){
	return strcmp(st1->name, st2->name);	
}


int age_key(Student* st1, Student* st2){
	return st1->age > st2->age;
}	


