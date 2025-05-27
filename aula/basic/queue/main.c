#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main()
{

    Queue* minha_fila = create_queue();

    enqueue(minha_fila, 10);
    enqueue(minha_fila, 20);
    enqueue(minha_fila, 30);
    enqueue(minha_fila, 40);

    //print_queue(minha_fila);

    dequeue(minha_fila);

    printf("Dequeue: %d \n", dequeue(minha_fila));

    printf("Dequeue: %d \n", dequeue(minha_fila));

    //printf("%d \n", front(minha_fila));

    //print_queue(minha_fila);

    free_queue(minha_fila);

    return 0;
}
