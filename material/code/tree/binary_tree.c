#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


node_t* create_node(int value){
    node_t* new_node = (node_t*) malloc(sizeof(node_t));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}//end create_node


node_t* insert(node_t* root, int data){
    if(!root) {
        return create_node(data);
    }

    if( root->data > data ) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}//end insert()


node_t* free_bt(node_t* root) {

    if(root){
        root->left  = free_bt(root->left);
        root->right = free_bt(root->right);

        free(root);
        root = NULL;
    }

    return root;
}//end erase()


node_t* search(node_t* root, int data){
    if(!root)
        return NULL;

    if(root->data == data)
        return root;

    if( root->data > data )
        return search(root->left, data);
    else
        return search(root->right, data);
}//end search()


int get_amount_of_nodes(node_t* root){
    if(!root)
        return 0;

    return 1 + get_amount_of_nodes(root->left) + get_amount_of_nodes(root->right);
}//end get_amount_of_nodes


int height(node_t* root){
    if(!root) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return 1 + (lheight > rheight ? lheight : rheight);
}//end height()


int is_leaf(node_t* node){
    return (node && !node->left && !node->right ? 1 : 0);
}//end isLeaf()

int is_balanced(node_t* node){
    if(!node)
        return 1;

    if(!is_balanced(node->left) || !is_balanced(node->right))
        return 0;

    return (abs(height(node->left) - height(node->right)) > 1 ? 0 : 1);
}//end isBalanced()


void pre_order(node_t* root){
    if(root != NULL){
        printf("%d\n", root->data);

        pre_order(root->left);
        pre_order(root->right);
    }
}//end pre_order()


void post_order(node_t* root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);

        printf("%d\n", root->data);
    }
}//end post_order()


void in_order(node_t* root){
    if(root != NULL){
        in_order(root->left);
        printf("%d\n", root->data);
        in_order(root->right);
    }
}//end in_order()


void breadth_first_search(node_t* root){
    queue_t* queue = NULL;
    node_t* node   = NULL;

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

    free_queue(queue);
}//end breadth_first_search()

