#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char *nome;
    float *notas;
} Aluno;

Aluno* aloca_aluno(int tam_nome, int qt_notas){
    Aluno* pt_aluno = (Aluno *) malloc(sizeof(Aluno));
    pt_aluno->nome = (char *) malloc(tam_nome*sizeof(char));
    pt_aluno->notas = (float *) malloc(qt_notas*sizeof(float));

    return pt_aluno;
}//end aloca_aluno

void libera_aluno(Aluno* pt_aluno){
    free(pt_aluno->nome);
    free(pt_aluno->notas);
    free(pt_aluno);
}


void imprimir_aluno(Aluno* pt_aluno, int qt_notas){
    printf("+=========================\n");
    printf("Nome: %s\n", pt_aluno->nome);
    for(int i = 0; i < qt_notas; i++){
        printf("Nota %d: %.2f\n", i+1, pt_aluno->notas[i]);
    }

    printf("+=========================\n");
}


int main(){
    int qt_notas;
    Aluno *pt_aluno = NULL;

    printf("Informe a quantidade de notas:\n");
    scanf("%d", &qt_notas);
    getchar();

    pt_aluno = aloca_aluno(100, qt_notas);


    printf("Nome:\n");
    scanf("%[^\n]s", pt_aluno->nome);

    for(int i = 0; i < qt_notas; i++){
        printf("Informe nota %d:\n", i+1);
        scanf("%f", &pt_aluno->notas[i]);
    }


    imprimir_aluno(pt_aluno, qt_notas);

    libera_aluno(pt_aluno);


    return 0;
}
