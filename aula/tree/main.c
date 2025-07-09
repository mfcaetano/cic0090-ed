#include <stdio.h>
#include "tree.h"
#include "queue.h"


int main(){
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
    root = insert(root, 100);
    root = insert(root, 200);

    node_t* no = get_menor_valor(root);

    if(no)
        printf("Menor No é: %d\n", no->data);


    /*node_t* node = search(root, 19);

    if(node)
        printf("O nó foi encontrado: %d \n", node->data);
    else
        printf("O nó não foi encontrado! \n");
    */

    //printf("Busca em profundidade: \n");
    breadth_first_search(root);

    printf("Percorrer em Pre-Ordem: \n");
    pre_order(root);

    printf("Percorrer em Pos-Ordem: \n");
    pos_order(root);

    printf("Percorrer em In-Ordem: \n");
    in_order(root);

    printf("Altura da arvore é: %d \n", height(root));


    node_t* n_search = search(root, 100);

    if(n_search)
        printf("Nó encontrado foi: %d \n", n_search->data);
    else
        printf("Nó não foi encontrado \n");


    printf("Nó é folha: %d\n", is_leaf(NULL));

    printf("Quantidade de nós: %d \n", get_amount_of_nodes(root));


    if(is_balanced(root)){
        printf("Arvore balanceada!\n");
    }
    else{
        printf("Arvore nao é balanceada!\n");
    }

    

}//end main


