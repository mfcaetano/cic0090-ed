#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"


int main() {
    node_t* root = NULL;

    root = insert(root, 50);
    root = insert(root, 17);
    root = insert(root, 72);
    root = insert(root, 12);
    root = insert(root, 23);
    root = insert(root, 54);
    root = insert(root, 76);
    root = insert(root, 9);
    root = insert(root, 14);
    root = insert(root, 19);
    root = insert(root, 67);

    printf("Quantidade de nos: %d \n", get_amount_of_nodes(root));

    node_t* node = search(root, 19);

    if(node){
        printf("O no foi encontrado: %d \n", node->data);
    }else{
        printf("O no  não foi encontrado! \n");
    }

    if(is_leaf(node)){
        printf("O nó %d é folha!\n", node->data);
    }else{
        if(node)
            printf("O nó %d Não é folha!\n", node->data);
    }

    printf("Árvore com altura: %d \n", height(root));

    printf("\nBusca em Largura \n");
    breadth_first_search(root);

    printf("\nPré-Ordem\n");
    pre_order(root);

    printf("\nIn-Ordem\n");
    in_order(root);


    printf("\nPós-Ordem\n");
    post_order(root);


    if(is_balanced(root)){
        printf("Esta árvore é balanceada!\n");
    }else{
        printf("Esta árvore NÃO é balanceada!\n");
    }


    free_bt(root);

    printf("Hello, World!\n");
    return 0;
}//end main()