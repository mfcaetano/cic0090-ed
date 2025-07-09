#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

node_t* create_node(int data){
    node_t* new_node = (node_t *) malloc(sizeof(node_t));

    if(!new_node){
        fprintf(stderr, "Falha na alocação de memória!\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}//end create_node

node_t* insert(node_t* root, int data){
    if(!root){
        return create_node(data);
    }

    if(root->data > data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }

    return root;
}//end insert()


void pre_order(node_t* root){

    if(root){
        printf("%d\n", root->data);

        pre_order(root->left);
        pre_order(root->right);
    }

}//end pre_order

void pos_order(node_t* root){
    if(root){
        pos_order(root->left);
        pos_order(root->right);

        printf("%d\n", root->data);
    }
}//pos_order()

void in_order(node_t* root){
if(root){
        in_order(root->left);
        printf("%d\n", root->data);
        in_order(root->right);
    }
}//end in_order()


node_t* get_menor_valor(node_t* root){

    if(!root->left){
        return root;
    }

    return get_menor_valor(root->left);
}//end

int is_leaf(node_t* node){
    return(node && !node->left && !node->right ? 1 : 0);
}//end is_leaf()


int get_amount_of_nodes(node_t* root){
    if(!root)
        return 0;

    return 1 + get_amount_of_nodes(root->left) + get_amount_of_nodes(root->right);
}//end get_amount_of_nodes()


int is_balanced(node_t* node){
    if(!node)
        return 1;

    if(!is_balanced(node->left) || !is_balanced(node->right) )
        return 0;

    return ( abs(height(node->left) - height(node->right)) > 1 ? 0 : 1 );
    


}//end is_balanced()

node_t* search(node_t* root, int data){
    if(!root)
        return NULL;

    if(root->data == data)
        return root;
    
    if( root->data > data)
        return search(root->left, data);
    else
        return search(root->right, data);

}//end search

int height(node_t* root){
    if(!root)
        return 0;

    int lelft_height = height(root->left);
    int right_height = height(root->right);

    return 1 + (lelft_height > right_height ? lelft_height : right_height);
}//end height


void breadth_first_search(node_t* root){
    queue_t* queue = NULL;
    node_t* node = NULL;

    if(root == NULL)
        return;

    queue = get_queue();

    enqueue(queue, root);

    while(!isEmpty(queue)){
        dequeue(queue, &node);

        printf("[%d]\n", node->data);

        if(node->left)
            enqueue(queue, node->left);

        if(node->right)
            enqueue(queue, node->right);
    }

}//end breadth_fisrt_search()