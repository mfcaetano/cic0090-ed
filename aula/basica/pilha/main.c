#include "stack.h"
#include <stdio.h>

int main(){
  Pilha* pilha = cria_pilha();
  int valor;
  
  for(int i = 0; i < 10; i++){
    push(pilha, i+1);
  }
  
  printf("Pilha:\n");
  while( pop(pilha, &valor) ){
    printf("%d \n", valor);
  }
  
  free_pilha(pilha);
  
}

