#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bst.h"

void print_node(t_btree *node);
void test_item(int test_no, int test_item);

int main() {
    int items[] = { 1, 2, 100000, 0, -1, -25 };
    int length = (int) (sizeof(items) / sizeof(items[0]));

    for (int i = 0; i < length; i++) {
        if (i != 0)
            printf("\n");

        test_item(i + 1, items[i]);
    }

    return 0;
}

void test_item(int test_no, int test_item) {
    t_btree *node = bstree_create_node(test_item);

    printf("\nTEST %d:\n\t", test_no);
    printf("Input: item = %d\n\t", test_item);
    printf("Output: ");

    bool pass = true;
    if (node == NULL) {
        printf("NULL\n\t");
        pass = false;
    } else {
        print_node(node);
        if (node->item != test_item || node->left != NULL ||
            node -> right != NULL) {
            pass = false;
        }
    }

    if (pass)
        printf("\n\tSUCCESS");
    else
        printf("\n\tFAIL");

    bstree_destroy(node);
}

void print_node(t_btree *node) {
    printf("Node %d: ", node->item);

    if (node->left == NULL)
        printf("Left = n/a, ");
    else
        printf("Left = %d, ", node->left->item);


    if (node->right == NULL)
        printf("Right = n/a;");
    else
        printf("Right = %d;", node->right->item);
}
