
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *item;
  struct Node* next;
} Node;

typedef struct{
  Node* top;
  int size;
} Stack;

Stack* create_stack();
void free_stack(Stack* stack);

Node* create_node(const char* item);
void free_node(Node* node);

//empilhar um aluno na pilha
void push(Stack* stack, const char* item);

//desempilhar um aluno
char* pop(Stack* stack);

//imprime pilha
void print_stack(Stack* stack);



Stack* create_stack(){
  Stack* stack = (Stack *) malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;
  
  return stack;
}//end create_stack();


void free_stack(Stack* stack){
  Node* pt_aux = stack->top;

  while(pt_aux){
    stack->top = stack->top->next;
    free_node(pt_aux);
    
    pt_aux = stack->top;
  }//end while

  free(stack);
}//end free_stack()


Node* create_node(const char* item){
  Node* node = (Node *) malloc(sizeof(Node));
  
  node->item = (char *) malloc(strlen(item)+1);
  strcpy(node->item, item);
  
  node->next = NULL;
  
  return node;
}//end create_node()


void free_node(Node* node){
    free(node->item);
    free(node);   
}//end free_node()


//empilhar um aluno na pilha
void push(Stack* stack, const char* item){
  Node* node = create_node(item);
  
  node->next = stack->top;
  stack->top = node;
  stack->size++;
}//end push()


//desempilhar um aluno
char* pop(Stack* stack){
  if(stack->size == 0)
    return NULL;
  
  char* item = stack->top->item;
  Node* pt_aux = stack->top;
  stack->top = stack->top->next;
  stack->size--;
  
  free(pt_aux);
  return item;
}//end pop



void print_stack(Stack* stack){
  if(stack->size == 0)
    return;
    
  Node* it = stack->top;
  
  while(it){
    printf("%s\n", it->item);
    
    it = it->next;
  }//end while
}//end print_stack()



int main(){
  char uinput[200];
  char *aux;
  Stack* numeros = create_stack();
  Stack* palavras = create_stack();
  
  int flag = 0;
  while(!flag){
    scanf("%s", uinput);
    
    if(strcmp(uinput, "end")){
      if(uinput[0] <= 57 && uinput[0] >= 48){
        push(numeros, uinput);
      }else{
        push(palavras, uinput);
      }
    }else{
      flag = 1;
    }
  }//end while
  
  printf("Palavras:\n");
  while(palavras->size){
    aux = pop(palavras);
    printf("%s\n", aux);
    free(aux);
  }
  
  printf("Numeros:\n");
  while(numeros->size){
    aux = pop(numeros);
    printf("%s\n", aux);
    free(aux);
  }
  
  free_stack(numeros);
  free_stack(palavras);
  
}//end main()
