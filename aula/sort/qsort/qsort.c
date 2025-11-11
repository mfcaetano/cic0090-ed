#include <stdio.h>
#include <stdlib.h>

/*
  > 0 - se o valor apontado por 'a' deve vir depois de 'b'
  < 0 - se 'a' deve vir ANTES de 'b'
  = 0 - se são iguais
*/


int inversa( const void * a, const void * b){
  return  (*((int *) b)) - (* ((int *) a));
}

int normal( const void * a, const void * b){
  return  (*((int *) a)) - (* ((int *) b));
}

int main(){
  const int TAM = 12; // número de elementos no vetor

  // Vetor de inteiros a ser ordenado
  int v[] = {0, 3, 1, 4, 5, 6, -1, 9, 2, 3, 7, 8};
  
  qsort(v, TAM, sizeof(int), normal);
  
  
  
  printf("Vetor ordenado: \n");
  for(int i = 0; i < TAM; i++){
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;

}
