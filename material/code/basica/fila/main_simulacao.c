#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // para sleep()
#include <time.h>     // para srand() e rand()
#include "queue.h"

// Função que simula a produção de uma tarefa
void produzir(Queue* buffer, int id_tarefa) {
    enqueue(buffer, id_tarefa);
    printf("[PRODUTOR] Tarefa %d produzida e colocada no buffer.\n", id_tarefa);
}

// Função que simula o consumo de uma tarefa
void consumir(Queue* buffer) {
    if (is_empty(buffer)) {
        printf("[CONSUMIDOR] Nenhuma tarefa disponível. Aguardando...\n");
    } else {
        int tarefa = dequeue(buffer);
        printf("[CONSUMIDOR] Tarefa %d retirada do buffer e processada.\n", tarefa);
    }
}

// Programa principal
int main() {
    srand(time(NULL)); // inicializa gerador de números aleatórios

    Queue* buffer = create_queue();

    printf("=== Simulação: Produtor e Consumidor com Fila Encadeada ===\n");
    printf("Cada iteração representa 1 segundo.\n");
    printf("----------------------------------------------------------\n");

    // Loop simulando 15 segundos de execução
    for (int tempo = 1; tempo <= 15; tempo++) {
        printf("\n[Tempo %02d]\n", tempo);

        // O produtor tem 60% de chance de criar uma nova tarefa
        if (rand() % 100 < 90) {
            int nova_tarefa = rand() % 1000; // ID aleatório da tarefa
            produzir(buffer, nova_tarefa);
        } else {
            printf("[PRODUTOR] Nenhuma nova tarefa neste ciclo.\n");
        }

        // O consumidor tenta processar uma tarefa
        if (rand() % 100 < 30) {
            consumir(buffer);
        } else {
            printf("[CONSUMIDOR] O consumidor está ocioso neste ciclo.\n");
        }

        // Mostra o estado atual do buffer
        print_queue(buffer);

        // Aguarda 1 segundo antes do próximo ciclo
        sleep(1);
    }

    printf("\n=== Fim da simulação ===\n");
    free_queue(buffer);
    return 0;
}
