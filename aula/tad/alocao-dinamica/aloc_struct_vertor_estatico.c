#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_NOME 20
#define TAM_MAX_NOTAS 2
#define TAM_MAX_ALUNOS 3


typedef struct {
    char nome[TAM_MAX_NOME];
    float notas[TAM_MAX_NOTAS];
} Aluno;


void ler_dados(Aluno *pt_aluno, int indice_aluno);


int main() {
    Aluno alunos[TAM_MAX_ALUNOS];


    for(int i = 0; i < TAM_MAX_ALUNOS; i++){
        ler_dados(&alunos[i], i+1);    
    }


    for(int i = 0; i < TAM_MAX_ALUNOS; i++){

        printf("Nome do aluno %d: %s\n", i, alunos[i].nome);

        for(int j = 0; j < TAM_MAX_NOTAS; j++){
            printf("Nota %d do aluno %d: %f\n", j+1,i, alunos[i].notas[j]);
        }
    }


    return 0;
}


void ler_dados(Aluno * pt_aluno, int indice_aluno){

    printf("Informe o nome do aluno %d: \n", indice_aluno);
    //scanf("%[^\n]s", (*pt_aluno).nome);
    scanf("%[^\n]s", pt_aluno->nome); //outra forma de fazer
    fflush(stdin);

    for(int i = 0; i < TAM_MAX_NOTAS; i++){
        printf("Informe a nota %d do aluno %d:\n", i+1, indice_aluno);
        scanf("%f", &pt_aluno->notas[i]);
        getchar();
    }




} //end ler_dados()
