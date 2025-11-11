#include "list.h"
#include "student.h"
#include "sort.h"
#include <stdio.h>

int main(){
	List* lt = create_list();

	insert(lt, 0, create_student("Marcos Caetano", 22, "00000000001"));
	insert(lt, 1, create_student("Pedro Paulo", 32, "00000000002"));
	insert(lt, 2, create_student("Carlos Eduardo", 44, "00000000003"));
	insert(lt, 3, create_student("Amado Batista", 12, "00000000004"));
	insert(lt, 4, create_student("Maria Joaquina", 19, "00000000005"));

	print_list(lt);


	printf("\n\nOrdenação Por Nome\n");
	bubble_sort(lt, name_key);

	printf("\nLista Ordenada por Nome!\n");
	print_list(lt);

	printf("\n\nOrdenação por Idade\n");
	bubble_sort(lt, age_key);

	printf("\nLista Ordenada por Idade!\n");
	print_list(lt);

	free_list(lt);
}//end main()