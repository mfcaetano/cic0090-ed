#include <stdio.h> // Para entrada e saída (printf, scanf)

int main() {
    // Usamos 'long long' para 'n' e 'soma_total_esperada' para evitar estouro de inteiro.
    // 'n' pode ser até 2 * 10^5, e a soma dos números até 'n' pode ser muito grande,
    // excedendo o limite de um 'int' comum.
    long long n; 
    scanf("%lld", &n); // Lê o valor de n (use %lld para long long)

    // Calcula a soma esperada de todos os números de 1 a n.
    // A fórmula é n * (n + 1) / 2.
    long long soma_total_esperada = n * (n + 1) / 2;
    long long soma_numeros_fornecidos = 0; // Inicializa a soma dos números que serão lidos

    // Loop para ler os n-1 números e somá-los.
    // O loop vai de 0 até n-2, lendo um total de n-1 números.
    for (int i = 0; i < n - 1; ++i) {
        long long num;
        scanf("%lld", &num); // Lê cada número fornecido
        soma_numeros_fornecidos += num; // Adiciona o número à soma
    }

    // O número que está faltando é a diferença entre a soma total esperada
    // e a soma dos números que foram fornecidos.
    long long numero_ausente = soma_total_esperada - soma_numeros_fornecidos;

    printf("%lld\n", numero_ausente); // Imprime o número ausente

    return 0; // Indica que o programa terminou com sucesso
}
