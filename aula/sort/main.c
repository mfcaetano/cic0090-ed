#include "list.h"
#include "student.h"
#include <stdio.h>
#include "sort.h"

int main(){
  List* lt = create_list();
  
  insert(lt, 0, create_student("Marcos Caetano", 45, "001"));
  insert(lt, 1, create_student("Pedro Paulo", 32, "002"));
  insert(lt, 2, create_student("Carlos Eduardo", 44, "003"));
  insert(lt, 3, create_student("Amado Batista", 12, "004"));
  insert(lt, 4, create_student("Maria Joaquina", 19, "005"));
  
  print_list(lt);
  
  bubble_sort(lt, name_key);
  
  printf("Ordenado por nome: \n");
  print_list(lt);
  
  bubble_sort(lt, age_key);
  
  printf("Ordenado por Idade: \n");
  print_list(lt);
  
  free_list(lt);

}
