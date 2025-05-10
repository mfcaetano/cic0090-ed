#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_NOME 20;
#define TAM_MAX_NOTAS 2


typedef struct {
    char nome[TAM_MAX_NOME];
    float notas[TAM_MAX_NOTAS];
} Aluno;


void ler_dados(Aluno *pt_aluno);


int main() {
    Aluno aluno;

    ler_dados(&aluno);


    printf("Nome do aluno: %s\n", aluno.nome);

    for(int i = 0; i < TAM_MAX_NOTAS; i++){
        printf("Nota %d: %f\n", i+1, aluno.notas[i]);
    }


    return 0;
}


void ler_dados(Aluno * pt_aluno){

    printf("Informe seu nome: \n");
    //scanf("%[^\n]s", (*pt_aluno).nome);
    scanf("%[^\n]s", pt_aluno->nome); //outra forma de fazer

    for(int i = 0; i < TAM_MAX_NOTAS; i++){
        printf("Informe nota %d:\n", i+1);
        scanf("%f", &pt_aluno->notas[i]);
    }




} //end ler_dados()
