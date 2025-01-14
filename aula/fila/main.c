#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	Queue* minha_fila = create_queue();

	enqueue(minha_fila, 10);
	enqueue(minha_fila, 20);
	enqueue(minha_fila, 30);
	enqueue(minha_fila, 45);

	print_queue(minha_fila);

	printf("Dequeue: %d \n", dequeue(minha_fila));

	print_queue(minha_fila);


	free_queue(minha_fila);

}