
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct node_t {
    int data;
    struct node_t* left;
    struct node_t* right;
} node_t;

node_t* create_node(int value);

node_t* insert(node_t* root, int data);
node_t* free_bt(node_t* root);
node_t* search(node_t* root, int data);

int get_amount_of_nodes(node_t* root);
int height(node_t* root);
int is_leaf(node_t* node);
int is_balanced(node_t* node);

void pre_order(node_t* root);
void post_order(node_t* root);
void in_order(node_t* root);

void breadth_first_search(node_t* root);

#endif