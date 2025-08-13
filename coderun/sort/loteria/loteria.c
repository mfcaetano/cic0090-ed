#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mencao[3], nome[101];
} aluno_t;


int converte_mencao(char* mencao) {
    int resultado = 0;

    if (strcmp(mencao, "SS") == 0) resultado = 9;
    if (strcmp(mencao, "MS") == 0) resultado = 7;
    if (strcmp(mencao, "MM") == 0) resultado = 5;
    if (strcmp(mencao, "MI") == 0) resultado = 3;
    if (strcmp(mencao, "II") == 0) resultado = 1;
    if (strcmp(mencao, "SR") == 0) resultado = 0;

    return resultado;
}//end converte_mencao
 

int mencao_cmp(char* a, char* b) {
    return converte_mencao(b) - converte_mencao(a);
}//end mencao_cmp


/* -1 se primeiro é melhor que segundo, 0 se forem iguais, 1 se o segundo for melhor. */
int cmp(const void* a, const void* b) {
    int resultado = mencao_cmp(((aluno_t *)a)->mencao, ((aluno_t*)b)->mencao);
    if(0 != resultado) return resultado;

    return strcmp(((aluno_t *)a)->nome, ((aluno_t*)b)->nome);
}

int main() {
    aluno_t alunos[500];
    int i, N;

    scanf("%d", &N);
    for (i = 0; i < N; ++i)
        scanf("%s %[^\n]s", alunos[i].mencao, alunos[i].nome);

    qsort(alunos, N, sizeof(aluno_t), cmp);

    for (i = 0; i < N; ++i)
        printf("%s %s\n", alunos[i].mencao, alunos[i].nome);

    return 0;
}
