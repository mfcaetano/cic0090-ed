#include "stack.h"

int main(void) {
    Stack* s = create_stack();

    printf("Inserindo elementos na pilha...\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    print_stack(s);

    int topo;
    if (peek(s, &topo)) {
        printf("Topo atual: %d\n", topo);
    }

    printf("\nRemovendo elementos:\n");
    while (pop(s, &topo)) {
        printf("Removido: %d\n", topo);
        print_stack(s);
    }

    printf("\nTentando remover de pilha vazia...\n");
    if (!pop(s, &topo)) {
        printf("Nada a remover — pilha está vazia.\n");
    }

    free_stack(s);
    return 0;
}

