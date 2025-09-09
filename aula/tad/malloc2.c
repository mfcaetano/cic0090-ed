
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str_aluno {
  char* nome;
  float* notas;
  int i_nota;
  int len;
} str_aluno;


str_aluno* cria_aluno(char* buff_nome, int qt_notas);
int cadastra_nota(str_aluno* aluno, float *nota);
float calcula_media(str_aluno* aluno);

void libera_aluno(str_aluno* aluno);




str_aluno* cria_aluno(char* buff_nome, int qt_notas){
  str_aluno* aluno = (str_aluno *) malloc(sizeof(str_aluno));
  
  if(!aluno){
    printf("Não foi possível alocar memoria para aluno\n");
    exit(1);
  }
  
  aluno->nome = (char *) malloc((strlen(buff_nome)+1) * sizeof(char));
  
  if(!aluno->nome){
    free(aluno);
    printf("Não foi possível alocar memória para nome do aluno\n");
    exit(1);
  }
  
  strcpy(aluno->nome, buff_nome);
  
  aluno->notas = (float *) malloc(qt_notas*sizeof(float));
  
  if(!aluno->notas){
    free(aluno->nome);
    free(aluno);
    printf("Não foi possível alocar memoria para nota");
    exit(1);
  }
  
  aluno->i_nota = 0;
  aluno->len = qt_notas;
  
  return aluno;
}//end cria_aluno()


int cadastra_nota(str_aluno* aluno, float *nota){
  int tem_espaco = aluno->i_nota < aluno->len;
  
  if(tem_espaco){
    aluno->notas[aluno->i_nota] = *nota;
    aluno->i_nota++;
  }
  
  return tem_espaco;
}//end cadastra_nota()

float calcula_media(str_aluno* aluno){
}

void libera_aluno(str_aluno* aluno){
}

int main(){
  char buff_nome[100];
  float buff_nota;
  int qt_notas;
  str_aluno* pt_aluno = NULL;
  
  
  printf("Informe nome: \n");
  scanf("%[^\n]", buff_nome);
  
  printf("Informe a qt de notas: \n");
  scanf("%d", &qt_notas);
  
  pt_aluno = cria_aluno(buff_nome, qt_notas);
  
  for(int i = 0; i < qt_notas; i++){
    printf("Informe nota %d:\n", i+1);
    scanf("%f", &buff_nota);
    
    if(!cadastra_nota(pt_aluno, &buff_nota) ){
      printf("Número maior de notas informado!\n");
      exit(1);
    }
  }
  
  


}


