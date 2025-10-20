#include <stdio.h>
#include "queue.h"

int main() {
    printf("=== Exemplo de uso de Fila Encadeada ===\n");

    Queue* fila = create_queue();

    // Inserindo elementos
    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);
    print_queue(fila);

    // Consultando o primeiro elemento
    printf("Primeiro da fila: %d\n", front(fila));

    // Removendo um elemento
    int removido = dequeue(fila);
    printf("Elemento removido: %d\n", removido);
    print_queue(fila);

    // Inserindo mais elementos
    enqueue(fila, 40);
    enqueue(fila, 50);
    print_queue(fila);

    // Removendo todos até a fila esvaziar
    while (!is_empty(fila)) {
        printf("Removendo: %d\n", dequeue(fila));
    }

    print_queue(fila);

    free_queue(fila);

    printf("Programa encerrado.\n");
    return 0;
}
