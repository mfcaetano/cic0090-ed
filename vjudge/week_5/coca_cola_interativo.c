#include <stdio.h>

int calcula_coca(int n) {
    int total = 0;

    while (n >= 3) {
        total += n / 3; // Soma o número de garrafas trocadas
        n = n / 3 + n % 3; // Atualiza o número de garrafas com o restante
    }

    // Caso sobre exatamente uma garrafa extra para troca
    if (n == 2) {
        total++;
    }

    return total;
}

int main() {
    int num;

    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;
        
        printf("%d\n", calcula_coca(num));
    }

    return 0;
}