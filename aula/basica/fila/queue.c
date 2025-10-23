#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue * create_queue(){
    Queue* q = (Queue *) malloc(sizeof(Queue));
    
    if(q == NULL){
        printf("Error: falha ao alocar memória para a fila. \n");
        exit(1);
    }
    
    q->begin = NULL;
    q->end = NULL;
    q->size = 0;
    
    return q;
}//end create_queue()

Node* create_node(int item){
    Node* node = (Node *) malloc(sizeof(Node));
    
    if( node == NULL){
        printf("Não foi possível alocar memória para nó!\n");
        exit(1);
    }
    
    node->item = item;
    node->next = NULL;
    
    return node;
}//end create_node()

void enqueue(Queue* q, int item){
    Node* node = create_node(item);
    
    if(is_empty(q)){
        q->begin = node;
        q->end = node;
    }else {
      q->end->next = node;
      q->end = node;
    }
    
    q->size++;
}//end enqueue()

int dequeue(Queue* q){
    if (is_empty(q)){
        printf("Fila vazia. \n");
        free_queue(q);
        exit(1);
    }
    
    Node* aux = q->begin;
    int valor = aux->item;
    q->begin = q->begin->next;
    
    free(aux);
    q->size--;
    
    if (q->begin == NULL)
        q->end = NULL;
    
    return valor;
}

int front(Queue* q){
    if(is_empty(q)){
        printf("Fila vazia!\n");
        free_queue(q);
        exit(1);
    }
    
    return q->begin->item;
}//end front()


void print_queue(Queue* q){
    if(is_empty(q)){
        printf("Fila vazia!\n");
        return;
    }
    
    Node* atual = q->begin;
    printf("Fila: ");
    
    while(atual){
      printf("%d ", atual->item);
      
      atual = atual->next;
    }//end while
    
    printf("\n");
}//end print_queue()

void free_queue(Queue* q){
    if(!q)
      return;

    while(!is_empty(q))
        dequeue(q);
          
    free(q);
}//end free_queue()

int is_empty(Queue* q){
  return (q->size == 0);
}//end is_empty()
