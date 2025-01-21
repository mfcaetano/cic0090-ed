#include "sort.h"
#include <string.h>
#include <stdio.h>

void bubble_sort(List* lt, int (*sort_key)(Student* st1, Student* st2) ){

	if(is_empty(lt))
		return;

}//end bubble_sort()

int alpha_key(Student* st1, Student* st2){
	return strcmp(st1->name, st2->name);	
}


int age_key(Student* st1, Student* st2){
	return st1->age > st2->age;
}	


