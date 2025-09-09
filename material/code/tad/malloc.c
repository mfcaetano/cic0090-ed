#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str_aluno {
  char *nome;
  float *notas;
  int i_nota;
  int len;
} str_aluno;



str_aluno * cria_aluno(char* pt_nome, int qt_notas);
int cadastra_nota(str_aluno* aluno, float *nota);
float calcula_media(str_aluno* aluno);
void print_aluno(str_aluno* aluno);

void libera_aluno(str_aluno* aluno);


int main(){
  char buff_nome[100];
  float buff_nota;
  int qt_notas;
  str_aluno * pt_aluno = NULL;
  
  printf("Informe o nome: \n");
  scanf("%[^\n]", buff_nome);

  printf("Informe quantidade de notas: \n");
  scanf("%d", &qt_notas);

  pt_aluno = cria_aluno(buff_nome, qt_notas);

  for(int i = 0; i < qt_notas; i++){
    printf("Informe nota %d:\n", i+1);
    scanf("%f", &buff_nota);
    cadastra_nota(pt_aluno, &buff_nota);
  }

  print_aluno(pt_aluno);
    
  libera_aluno(pt_aluno);

}//end main


void libera_aluno(str_aluno* aluno){
  free(aluno->nome);
  free(aluno->notas);
  free(aluno);
}//end libera_aluno()


void print_aluno(str_aluno* aluno){
  printf("\nNome: %s\n", aluno->nome);

  for(int i = 0; i < aluno->i_nota; i++)
    printf("Nota %d: %.2f\n", i+1, aluno->notas[i]);

  printf("Media: %.2f\n", calcula_media(aluno));
}//end print_aluno()


float calcula_media(str_aluno* aluno){
  float media = 0;
  for(int i = 0; i < aluno->i_nota; i++)
    media += aluno->notas[i];

  return media / aluno->i_nota;
}//end calcula_media()


int cadastra_nota(str_aluno* aluno, float *nota){
  int tem_espaco = aluno->i_nota < aluno->len;

  if(tem_espaco){
    aluno->notas[aluno->i_nota] = *nota;
    aluno->i_nota++;
  }

  return tem_espaco;
}//end cadastra_nota


str_aluno * cria_aluno(char* pt_nome, int qt_notas){
  str_aluno* pt_aluno = (str_aluno *) malloc(sizeof(str_aluno));
  pt_aluno->nome = (char *) malloc( (strlen(pt_nome)+1)*sizeof(char));
  
  strcpy(pt_aluno->nome, pt_nome); 
  
  pt_aluno->notas = (float *) malloc(qt_notas*sizeof(float));
  pt_aluno->i_nota = 0;
  pt_aluno->len = qt_notas;

  return pt_aluno;
  
}///end cria_aluno()





