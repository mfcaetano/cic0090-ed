#include <stdio.h>
#include <stdlib.h>

#define QT_NOTAS 3

typedef struct aluno{
    char nome[100];
    float notas[3];
} Aluno;


void imprimir_aluno(Aluno* pt_aluno){
    printf("+=========================\n");
    printf("Nome: %s\n", pt_aluno->nome);
    for(int i = 0; i < QT_ALUNOS; i++){
        printf("Nota %d: %.2f\n", i+1, pt_aluno->notas[i]);
    }

    printf("+=========================\n");
}

int main() {

    Aluno aluno1;

    printf("Nome:\n");
    scanf("%[^\n]s", aluno1.nome);

    for(int i = 0; i < QT_NOTAS; i++){
        printf("Informe nota %d:\n", i+1);
        scanf("%f", &aluno1.notas[i]);
    }


    imprimir_aluno(&aluno1);

    return 0;
}
