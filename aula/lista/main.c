#include <stdio.h>
#include "lista.h"

int main(){
    Lista* lista = cria_lista();
    
   

    add(lista, 4);
    add(lista, 5);
    add(lista, 14);
    add(lista, 114);
    append(lista, 40);
    
    insert(lista, 2, 200);

    imprime_lista(lista);

 




    printf("hello \n");
}
