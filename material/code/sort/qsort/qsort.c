#include <stdio.h>
#include <stdlib.h>

/*
 * Função de comparação usada pelo qsort().
 * 
 * Retorna:
 *   > 0  → se o valor apontado por 'a' deve vir DEPOIS de 'b'
 *   < 0  → se 'a' deve vir ANTES de 'b'
 *   = 0  → se são iguais
 *
 * Como o retorno é (b - a), isso faz com que o maior valor
 * venha primeiro — ou seja, o vetor será ordenado em ordem DECRESCENTE.
 */
int inversa(const void* a, const void* b) {
    return (*((int*)b)) - (*((int*)a));
}

int main() {
    const int TAM = 12; // número de elementos no vetor

    // Vetor de inteiros a ser ordenado
    int v[] = {0, 3, 1, 4, 5, 6, -1, 9, 2, 3, 7, 8};

    // Ordena o vetor usando QuickSort genérico da stdlib
    // qsort(base, quantidade, tamanho_de_cada_elemento, funcao_comparacao)
    qsort(v, TAM, sizeof(int), inversa);

    // Imprime o vetor ordenado
    printf("Vetor ordenado (ordem decrescente):\n");
    for (int i = 0; i < TAM; ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

