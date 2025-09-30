#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct str_aluno {
  char *nome;
  float *notas;
  int qtd_notas;
  int i_notas; // indice para controle de insercao de notas
} str_aluno;


void ler_aluno_basico(char* nome, int* qt_notas);
void ler_aluno_notas(str_aluno* aluno);

float calcula_media(str_aluno* aluno);
int cadastra_nota(str_aluno* aluno, float nota);

str_aluno ** cria_alunos(int qt_alunos);
str_aluno * cria_aluno(char* pt_nome, int qt_notas);
void libera_aluno(str_aluno* aluno);
void libera_alunos(str_aluno** alunos, int qt_alunos);


int main(){
  char buff_nome[100];
  int buff_qt_notas;
  int qt_alunos;
  str_aluno ** alunos = NULL;

  printf("Informe a quantidade de alunos: \n");
  scanf("%d", &qt_alunos);
  getchar();
  
  alunos = cria_alunos(qt_alunos);
  
  for(int i = 0; i < qt_alunos; i++){
    printf("Aluno %d \n", i+1);
  
    ler_aluno_basico(buff_nome, &buff_qt_notas);
    alunos[i] = cria_aluno(buff_nome, buff_qt_notas);
    ler_aluno_notas(alunos[i]);
  }//end for i
  
  
  for(int i = 0; i < qt_alunos; i++){
    printf("\n\n Aluno %d \n", i+1);
    printf("Nome: %s \n", alunos[i]->nome);
    
    for(int j = 0; j <= alunos[i]->i_notas; j++ ){
      printf("Nota %d: %.2f \n", j+1, alunos[i]->notas[j]);
    }
    
    printf("Média: %.2f \n", calcula_media(alunos[i]));
  
  }//end for i
  
  libera_alunos(alunos, qt_alunos);

}//end main

void libera_alunos(str_aluno** alunos, int qt_alunos){
  for(int i = 0; i < qt_alunos; i++){
    libera_aluno(alunos[i]);
  }
  free(alunos);
}

void libera_aluno(str_aluno* aluno){

  free(aluno->nome);
  free(aluno->notas);
  free(aluno);
}

float calcula_media(str_aluno* aluno){
  float soma = 0.0;
  
  for(int i = 0; i <= aluno->i_notas; i++){
    soma += aluno->notas[i];
  }
  
  if(aluno->i_notas < 0) return 0.0; //nenhuma nota cadastrada
  
  return soma / (aluno->i_notas+1);
}//end calcula_media()


int cadastra_nota(str_aluno* aluno, float nota){
  int pode_cadastrar = aluno->i_notas + 1 < aluno->qtd_notas;

  if(pode_cadastrar){
    //aluno->i_notas++;
    aluno->notas[++aluno->i_notas] = nota; 
  }

  return pode_cadastrar;
}

void ler_aluno_notas(str_aluno* aluno){
  float nota;
  
  for(int i = 0; i < aluno->qtd_notas; i++){
    printf("Informe a nota %d: \n", i+1);
    scanf("%f", &nota);
    getchar();
    
    if(!cadastra_nota(aluno, nota)){
      printf("Nào foi possível cadastrar a nota %.2f\n", nota);
      exit(1);
    }
  }//end for

}//end ler_aluon_notas


void ler_aluno_basico(char* nome, int* qt_notas){
  printf("Informe nome:\n");
  scanf("%[^\n]", nome);
  
  printf("Informe a quantidade de notas: \n");
  scanf("%d", qt_notas);
  getchar();
}

str_aluno ** cria_alunos(int qt_alunos){
  str_aluno** alunos = (str_aluno **) malloc(qt_alunos*sizeof(str_aluno *));
  
  if(!alunos){
    printf("Nào foi possível alocar memória para Alunos \n");
    exit(1);
  }
  
  for(int i = 0; i < qt_alunos; i++){
    alunos[i] = NULL;
  }
  
  return alunos;
}//end cria_alunos


str_aluno * cria_aluno(char* pt_nome, int qt_notas){
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
  
  pt_aluno->notas = (float *) malloc(qt_notas*sizeof(float)); 
  
  if(!pt_aluno->notas){
    printf("Não foi possível alocar memória para aluno->n1\n");
    free(pt_aluno->nome);
    free(pt_aluno);
    exit(1);
  }
  
  strcpy(pt_aluno->nome, pt_nome); 
  pt_aluno->qtd_notas = qt_notas;
  pt_aluno->i_notas = -1; //nenhuma nota inserida ainda
  
  return pt_aluno;
  
}///end cria_aluno()







