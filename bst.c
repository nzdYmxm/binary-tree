#include <stdlib.h>
#include "bst.h"

#define CMP_GREATER 1
#define CMP_LESS -1

t_btree *bstree_create_node(int item) {
    t_btree *node = (t_btree*) malloc(sizeof(t_btree));

    if (node != NULL) {
        node->left = NULL;
        node->right = NULL;
        node->item = item;
    }

    return node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    int cmp = cmpf(item, root->item);

    if (cmp == CMP_GREATER) {
        if (root->right == NULL) {
            t_btree *node = bstree_create_node(item);

            if (node == NULL)
                exit(1);

            root->right = node;
        } else {
            bstree_insert(root->right, item, cmpf);
        }
    } else if (cmp == CMP_LESS) {
        if (root->left == NULL) {
            t_btree *node = bstree_create_node(item);

            if (node == NULL)
                exit(1);

            root->left = node;
        } else {
            bstree_insert(root->left, item, cmpf);
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root->left != NULL)
        bstree_apply_infix(root->left, applyf);

    applyf(root->item);

    if (root->right != NULL)
        bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    applyf(root->item);

    if (root->left != NULL)
        bstree_apply_prefix(root->left, applyf);

    if (root->right != NULL)
        bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root->right != NULL)
        bstree_apply_postfix(root->right, applyf);

    applyf(root->item);

    if (root->left != NULL)
        bstree_apply_postfix(root->left, applyf);
}

void bstree_destroy(t_btree *root) {
    if (root != NULL) {
        bstree_destroy(root->left);
        bstree_destroy(root->right);
        free(root);
    }
}
