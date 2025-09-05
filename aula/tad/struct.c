#include <stdio.h>

typedef struct str_aluno {
  char nome[50];
  float n1;
} str_aluno;

//typedef struct aluno str_aluno;

void ler_aluno(str_aluno *aluno);



int main(){
  str_aluno aluno;
  
  ler_aluno(&aluno);
  
  printf("Nome: %s nota: %.2f\n", aluno.nome, aluno.n1);
  
  
  //scanf("%[^\n]", aluno.nome);
  
  //printf("Nome informado: %s \n", aluno.nome);
  //printf("Tamanho: %zu %zu\n", sizeof(str_aluno), sizeof(aluno));

}

void ler_aluno(str_aluno* aluno){
  printf("Informe nome:\n");
  scanf("%[^\n]", (*aluno).nome);
  
  printf("Informe nota: \n");
  scanf("%f", &aluno->n1);
}
