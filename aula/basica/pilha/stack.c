#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* cria_pilha(void){
  Pilha* pilha = (Pilha *) malloc(sizeof(Pilha));
  //testa o retorno
  
  pilha->topo = NULL;
  pilha->tamanho = 0;
  
  return pilha;
}//end cria_pilha()

No* cria_no(int valor){
  No* no = (No *) malloc(sizeof(No));
  
  //testa do retorno
  
  no->dado = valor;
  no->proximo = NULL;
  
  return no;
}//end cria_no()


void free_pilha(Pilha* pilha){
  if(pilha == NULL) return;
  
  No* atual = pilha->topo;
  while(atual){
    No* aux = atual->proximo;
    free(atual);
    atual = aux;
  }//end while
  
  free(pilha);
}//end free_pilha()

int is_empty(Pilha* pilha){
  return (pilha == NULL || pilha->tamanho == 0);
}//end is_empty()

void push(Pilha* pilha, int valor){
  if (pilha == NULL) return;
  
  No* novo = cria_no(valor);
  novo->proximo = pilha->topo;
  pilha->topo = novo;
  pilha->tamanho++;
  
}//end push

int pop(Pilha* pilha, int* valor){
  if(is_empty(pilha))
    return 0;
    
  *valor = pilha->topo->dado;
  No* aux = pilha->topo;
  pilha->topo = aux->proximo;
  free(aux);
  pilha->tamanho--;
  return 1;
}//end pop()

int peek(Pilha* pilha, int* valor){
  if(is_empty(pilha))
    return 0;
    
  *valor = pilha->topo->dado;
  return 1;  
} //end peerk

