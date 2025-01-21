#include "student.h"
#include <stdio.h>

int main(){
	Student* st = create_student("Marcos Caetano", 22, "00000000001");

	print_student(st);

	free_student(st);
}