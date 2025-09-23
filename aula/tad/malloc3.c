#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str_aluno {
  char *nome;
  float *n1;
} str_aluno;


void ler_aluno(char* nome, float* nota1);

str_aluno * cria_aluno(char* pt_nome, float* pt_n1);
void libera_aluno(str_aluno* aluno);


int main(){
  char buff_nome[100];
  float buff_nota;
  str_aluno * pt_aluno = NULL;

  ler_aluno(buff_nome, &buff_nota);
  
  pt_aluno = cria_aluno(buff_nome, &buff_nota);
  
  printf("Nome: %s nota: %.2f\n", pt_aluno->nome, *pt_aluno->n1);
  
  libera_aluno(pt_aluno);

}//end main


void libera_aluno(str_aluno* aluno){

  free(aluno->nome);
  free(aluno->n1);
  free(aluno);
}

void ler_aluno(char* nome, float* nota1){
  printf("Informe nome:\n");
  scanf("%[^\n]", nome);
  
  printf("Informe nota: \n");
  scanf("%f", nota1);
}


str_aluno * cria_aluno(char* pt_nome, float* pt_n1){
  str_aluno* pt_aluno = (str_aluno *) malloc(sizeof(str_aluno));
  
  if(!pt_aluno){
    printf("Não foi possivel alocar memoria para Aluno \n");
    exit(1);
  }
  
  pt_aluno->nome = (char *) malloc( (strlen(pt_nome)+1)*sizeof(char));
  
  if(!pt_aluno->nome){
    printf("Não foi possível alocar memoria para aluno->nome\n");
    free(pt_aluno);
    exit(1);
  }
  
  pt_aluno->n1 = (float *) malloc(sizeof(float)); 
  
  if(!pt_aluno->n1){
    printf("Não foi possível alocar memória para aluno->n1\n");
    free(pt_aluno->nome);
    free(pt_aluno);
    exit(1);
  }
  
  strcpy(pt_aluno->nome, pt_nome); 
  *(*pt_aluno).n1 = *pt_n1;
  
  return pt_aluno;
  
}///end cria_aluno()







