#include <stdio.h>
#include <stdlib.h>


typedef struct abb_int {
    int value;
    struct abb_int *left;
    struct abb_int *right;
} abb_int;

abb_int *abb_insert(abb_int *root, int value) {
    if (root == NULL) {
        abb_int *new_node = malloc(sizeof(abb_int));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (value <= root->value) {
        root->left = abb_insert(root->left, value);
    } else if (value > root->value) {
        root->right = abb_insert(root->right, value);
    }
    
    return root;
}//end abb_insert()


void print_abb(abb_int* root) {
    printf("(");

    if (root) {
        printf("%d", root->value);
        printf(" ");
        print_abb(root->left);
        printf(" ");
        print_abb(root->right);
    }
    printf(")");

}//end print_abb()



int main() {
    int n, value;
    abb_int *root = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        root = abb_insert(root, value);
    }//end for i

    print_abb(root);

}//end main