#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

No* cria_no(int numero){
    No* pt_no = (No*) malloc(sizeof(No));

    pt_no->dado = numero;
    pt_no->proximo = NULL;

    return pt_no;
}//end cria_no

Lista* cria_lista(void){
    Lista* pt_lista = (Lista*) malloc(sizeof(Lista));

    pt_lista->inicio = NULL;
    pt_lista->tamanho = 0;

    return pt_lista;
}//end cria_lista


void add(Lista* lista, int item){
    No* pt_no = cria_no(item);

    pt_no->proximo = lista->inicio;
    lista->inicio = pt_no;
    lista->tamanho++;
}//end add

// Adiciona elemento em uma posição específica da lista
int insert(Lista* lista, int pos, int item){
  if(pos < 0 || pos > lista->tamanho)
    return RETORNO_ERRO;
    
  if( pos == 0){
    add(lista, item);
  }else{
    No* pt_no = cria_no(item);
    No* pt_aux = lista->inicio;
    
    for(int i = 0; i < pos - 1; i++)
      pt_aux = pt_aux->proximo;   
    
    pt_no->proximo = pt_aux->proximo;
    pt_aux->proximo = pt_no;
    
    pt_aux = pt_no;
  }
  
  lista->tamanho++;
  return RETORNO_OK;
}//end insert


void append(Lista* lista, int item){
  No* pt_no = cria_no(item);
  
  if (lista->inicio == NULL){
    lista->inicio = pt_no;
  } else{
    No* pt_aux = lista->inicio;
    //for(int i = 0; i < lista->tamanho-1; i++)
    
    while( pt_aux->proximo != NULL){
      pt_aux = pt_aux->proximo;
    }
    pt_aux->proximo = pt_no;
  }
  lista->tamanho++;
}//end append



// Imprime todos os elementos da lista
void imprime_lista(Lista* l) {
    No* atual = l->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}
