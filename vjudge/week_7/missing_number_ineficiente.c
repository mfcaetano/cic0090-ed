#include <stdio.h>   // Para scanf e printf
#include <stdbool.h> // Para usar o tipo bool

int main() {
    int n;
    scanf("%d", &n); // Lê o valor de n

    // Declara um array para armazenar os n-1 números.
    // O tamanho do array precisa ser n-1.
    int numeros_fornecidos[n - 1]; 

    // Lê os n-1 números e os armazena no array
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &numeros_fornecidos[i]);
    }

    // Loop externo: Tenta encontrar qual número de 1 a n está faltando
    for (int i = 1; i <= n; ++i) {
        bool encontrado = false; // Flag para verificar se o número 'i' foi encontrado

        // Loop interno: Percorre o array de números fornecidos para buscar 'i'
        for (int j = 0; j < n - 1; ++j) {
            if (numeros_fornecidos[j] == i) {
                encontrado = true; // O número 'i' foi encontrado
                break;             // Sai do loop interno, pois já achamos 'i'
            }
        }

        // Se o número 'i' não foi encontrado no array, ele é o número ausente
        if (!encontrado) {
            printf("%d\n", i); // Imprime o número ausente
            return 0;          // Encerra o programa assim que o número ausente é encontrado
        }
    }

    return 0; // Este return só será alcançado se houver um erro lógico
}
