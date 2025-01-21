
#ifndef __SORT_H__
#define __SORT_H__

#include "student.h"
#include "list.h"

int alpha_key(Student* st1, Student* st2);
int age_key(Student* st1, Student* st2);	


void bubble_sort(List* lt, int (*sort_key)(Student* st1, Student* st2) );


#endif