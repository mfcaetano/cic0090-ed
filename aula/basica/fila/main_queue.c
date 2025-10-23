
#include <stdio.h>
#include "queue.h"


int main(){
  Queue * fila = create_queue();
  
  enqueue(fila, 10);
  enqueue(fila, 20);
  enqueue(fila, 30);
  
  //print_queue(fila);
  
  while(!is_empty(fila))
    printf("%d ", dequeue(fila));
  
  free_queue(fila);
  


}//end main()



