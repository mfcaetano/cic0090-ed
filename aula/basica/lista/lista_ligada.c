#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[20];
  int fone;
} Aluno;

typedef struct No {
  Aluno* aluno;
  struct No* proximo;
} No;

typedef struct {
  No* primeiro;
  int tamanho;
} Lista;

Lista* cria_lista(void);
No* cria_no(Aluno* aluno);
Aluno* cria_aluno(const char* nome, int fone);

void libera_lista(Lista* lista);
void libera_no(No* no);

// push front
void add(Lista* lista, Aluno* aluno);

// push back
void append(Lista* lista, Aluno* aluno);

// insert at position [0..tamanho]
int insert(Lista* lista, int pos, Aluno* aluno);

// is empty?
int is_empty(Lista* lista);

// remove at position [0..tamanho-1], return the removed Aluno*
Aluno* pop(Lista* lista, int pos);

// print list
void imprime_lista(Lista* lista);


int main(){
  Lista* lista = cria_lista();
  
  

}//end main()


Lista* cria_lista(void){
    Lista* lista = (Lista *) malloc(sizeof(Lista));
    
    if(!lista){
      fprintf(stderr, "Memória não alocada para Lista \n");
      exit(EXIT_FAILURE);
    }
    
    lista->primeiro = NULL;
    lista->tamanho = 0;
    return lista;
}//end cria_lista()

No* cria_no(Aluno* aluno){
    No* no = (No *) malloc(sizeof(No));
    
    if(!no){
      fprintf(stderr, "Memória não alocada para No \n");
      exit(EXIT_FAILURE);
    }
  
    no->aluno = aluno;
    no->proximo = NULL;
    
    return no;
}//end cria_no()

Aluno* cria_aluno(const char* nome, int fone){
    Aluno* aluno = (Aluno *) malloc(sizeof(Aluno));
    
    if(!aluno){
      fprintf(stderr, "Memória não alocada para Aluno \n");
      exit(EXIT_FAILURE);
    }
  
    //strcpy(aluno->nome, nome);
    strncpy(aluno->nome, nome, sizeof(aluno->nome)-1);
    aluno->nome[sizeof(aluno->nome)-1] = '\0';
    aluno->fone = fone;
    
    return aluno;
}//end cria_aluno

void libera_lista(Lista* lista){
}

void libera_no(No* no){
}

void imprime_lista(Lista* lista) {
    if (!lista) {
        printf("(lista nula)\n");
        return;
    }
    printf("Lista (tamanho=%d):\n", lista->tamanho);
    No* atual = lista->primeiro;
    int idx = 0;
    while (atual) {
        printf("  [%d] %s - %s\n", idx, atual->aluno->nome, atual->aluno->fone);
        atual = atual->proximo;
        idx++;
    }
}






