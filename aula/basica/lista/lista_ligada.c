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

// search by nome; returns Aluno* or NULL
Aluno* search(Lista* lista, char* chave);


// print list
void imprime_lista(Lista* lista);


int main(){
  Lista* lista = cria_lista();
    
  add(lista, cria_aluno("Ana", 1));
  add(lista, cria_aluno("Caetano", 2));
  append(lista, cria_aluno("Paula", 3));
  append(lista, cria_aluno("Maria Jose", 4));
  
  imprime_lista(lista);
  
  int i = 2;
  
  Aluno* aluno = pop(lista, i);
  
  if(!aluno){
    libera_lista(lista);
    printf("Não foi possível remover aluno na posićão %d \n", i);
    exit(1);
  }
  
  printf("Aluno removido - nome %s - telefone: %d \n", aluno->nome, aluno->fone);
  
  free(aluno);
  
  
  aluno = search(lista, "Caetano");
  if(!aluno){
    libera_lista(lista);
    printf("Não foi possíve encontrar a chave: Caetano\n");
    exit(1);
  }
  
  printf("Aluno encontrado - nome %s - telefone: %d \n", aluno->nome, aluno->fone);
  
  imprime_lista(lista);
  
    
  libera_lista(lista);

  


/*    char buff_nome[200];
    int telefone;
    int qt_alunos;
    Lista* lista = cria_lista();
    
    printf("Informe a quantidade de alunos para cadastro: \n");
    scanf("%d", &qt_alunos);
    getchar();
    
    for(int i = 0; i < qt_alunos;i++){
        printf("Informe o nome[%d]\n", i+1);
        scanf("%[^\n]s", buff_nome);
        
        printf("Informe o telefone[%d]\n", i+1);
        scanf("%d", &telefone);
        getchar();
        
        add(lista, cria_aluno(buff_nome, telefone));
    }
  
    imprime_lista(lista);
    
    libera_lista(lista);
  
*/

}//end main()

// remove at position [0..tamanho-1], return the removed Aluno*
Aluno* pop(Lista* lista, int pos){

  if(!lista || pos < 0 || pos >= lista->tamanho)
    return NULL;
    
  No* removido;
  Aluno* aluno;
  
  if(pos == 0){
    removido = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
  }else {  
    No* atual = lista->primeiro;
    int i = 0;
    
    while(i < pos - 1 && atual){
      atual = atual->proximo;
      i++;
    }//end while
    
    if(!atual || !atual->proximo) return NULL;
    
    removido = atual->proximo;
    atual->proximo = removido->proximo;
  }//end if
  
  aluno = removido->aluno;
  free(removido);
  lista->tamanho--;
  return aluno;
}//end pop()



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
  No* atual = lista->primeiro;
  
  while(atual){
    lista->primeiro = lista->primeiro->proximo;
    libera_no(atual);
    atual = lista->primeiro;
  }
  
  free(lista);
}//end libera_lista()

void libera_no(No* no){
  free(no->aluno);
  free(no);
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
        printf("  [%d] %s - %d\n", idx, atual->aluno->nome, atual->aluno->fone);
        atual = atual->proximo;
        idx++;
    }
}


// search by nome; returns Aluno* or NULL
Aluno* search(Lista* lista, char* chave){
  if(!lista || !chave) return NULL;
  
  No* atual = lista->primeiro;
  
  while(atual){
    if(strcmp(atual->aluno->nome, chave) == 0){
      return atual->aluno;
    }
    
    atual = atual->proximo;
  }//end while
  
  return NULL;
}//end search


// push front
void add(Lista* lista, Aluno* aluno){
    No* no = cria_no(aluno);
    
    no->proximo = lista->primeiro;
    lista->primeiro = no; 
    lista->tamanho++;
}//end add


// push back
void append(Lista* lista, Aluno* aluno){
    No* no_novo = cria_no(aluno);
    
    //se a lista for vazia
    if(!lista->primeiro){
        lista->primeiro = no_novo;
    }else{
        No * atual = lista->primeiro;

        //enquanto atual tiver um enderećo válido
        while(atual->proximo){
            atual = atual->proximo;
        }
        
        atual->proximo = no_novo;  
    }//end if
    
    lista->tamanho++;
    
}//end append






