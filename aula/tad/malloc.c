#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str_aluno {
  char *nome;
  float n1;
} str_aluno;


void ler_aluno(str_aluno *aluno);

str_aluno * cria_aluno(char* pt_nome, float* pt_n1);
void libera_aluno(str_aluno* aluno);


int main(){
  char buff_nome[100];
  float buff_nota;
  str_aluno * pt_aluno = NULL;
  
  
  pt_aluno = cria_aluno("Joao de Deus", 3.0);
  
  //ler_aluno(pt_aluno);
  
  printf("Nome: %s nota: %.2f\n", pt_aluno->nome, pt_aluno->n1);
  
  libera_aluno(pt_aluno);

}//end main


void libera_aluno(str_aluno* aluno){
  free(aluno->nome);
  free(aluno);
}

str_aluno * cria_aluno(char* pt_nome, float* pt_n1){
  str_aluno* pt_aluno = (str_aluno *) malloc(sizeof(str_aluno));
  pt_aluno->nome = (char *) malloc( (strlen(pt_nome)+1)*sizeof(char));
  
  strcpy(pt_aluno->nome, pt_nome); 
  pt_aluno->n1 = *pt_n1;
  
  return pt_aluno;
  
}///end cria_aluno()



void ler_aluno(str_aluno* aluno){
  printf("Informe nome:\n");
  scanf("%[^\n]", (*aluno).nome);
  
  printf("Informe nota: \n");
  scanf("%f", &aluno->n1);
}



