#ifndef __TREE_H__
#define __TREE_H__

typedef struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
} node_t;


node_t* create_node(int data);
node_t* insert(node_t* root, int data);

node_t* search(node_t* root, int data);

int height(node_t* root);

int is_leaf(node_t* node);

int get_amount_of_nodes(node_t* root);

int is_balanced(node_t* node);


void breadth_first_search(node_t* root);

void pre_order(node_t* root);
void pos_order(node_t* root);
void in_order(node_t* root);

node_t* get_menor_valor(node_t* root);

#endif