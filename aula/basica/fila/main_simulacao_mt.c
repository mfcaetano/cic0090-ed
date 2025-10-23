#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include "queue.h"

#define TOTAL_TAREFAS 30

// Mutex e variáveis de condição para sincronização
pthread_mutex_t mutex_fila = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_fila_nao_vazia = PTHREAD_COND_INITIALIZER;


// Função executada pela thread produtora
void* produtor(void* arg) {
    Queue* fila = (Queue*) arg;
    pid_t tid = syscall(SYS_gettid);

    for (int i = 1; i <= TOTAL_TAREFAS; i++) {

        // Bloqueia a fila para inserir com segurança
        pthread_mutex_lock(&mutex_fila);
        enqueue(fila, i+1);

        printf("🟢 [Produtor %d] adicionou %d | Fila: %d\n", tid, i+1, fila->size);

        pthread_cond_signal(&cond_fila_nao_vazia); // Avisa que há itens na fila
        pthread_mutex_unlock(&mutex_fila);

        sleep(rand() % 2 + 1); // Simula tempo de produção
    }

    return NULL;
}

// Função executada pela thread consumidora
void* consumidor(void* arg) {
    Queue* fila = (Queue*) arg;
    pid_t tid = syscall(SYS_gettid);
    int tarefas_processadas = 0;

    while (tarefas_processadas < TOTAL_TAREFAS) {
        pthread_mutex_lock(&mutex_fila);

        // Espera enquanto a fila estiver vazia
        while (is_empty(fila)) {
            pthread_cond_wait(&cond_fila_nao_vazia, &mutex_fila);
        }

        // Remove uma tarefa da fila
        int item = dequeue(fila);
        pthread_mutex_unlock(&mutex_fila);


        printf("🔵 [Consumidor %d] removeu %d | Fila: %d\n", tid, item, fila->size);

        tarefas_processadas++;
        sleep(rand() % 3 + 1); // Simula tempo de processamento
        
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    Queue* fila = create_queue();

    pthread_t th_produtor, th_consumidor;

    printf("=== Simulação de Fila com Multithread ===\n");
    printf("Produtor e Consumidor iniciados...\n\n");

    // Cria as threads
    pthread_create(&th_produtor, NULL, produtor, fila);
    pthread_create(&th_consumidor, NULL, consumidor, fila);

    // Espera ambas terminarem
    pthread_join(th_produtor, NULL);
    pthread_join(th_consumidor, NULL);

    printf("\nTodas as tarefas foram processadas!\n");
    return 0;
}

