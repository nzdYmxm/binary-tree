#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bst.h"

void print_node(t_btree *node);
void print_tree(t_btree *root);
int cmpf(int a, int b);
void applyf(int item);

void test(int test_no, int *items, int items_count);

int main() {
    int items_1[] = { 1, 2, 100000, 0, -1, -25 };
    int length_1 = (int) (sizeof(items_1) / sizeof(items_1[0]));

    test(1, items_1, length_1);

    int items_2[] = { 1, 5, 10, 15, 2, 3, 4, 6, 7, 8, 9 };
    int length_2 = (int) (sizeof(items_2) / sizeof(items_2[0]));

    printf("\n\n");
    test(2, items_2, length_2);

    return 0;
}

void test(int test_no, int *items, int items_count) {
    t_btree *root = bstree_create_node(items[0]);

    bool error = root == NULL;

    if (!error) {
        for (int i = 1; i < items_count; i++) {
            bstree_insert(root, items[i], cmpf);
        }

        printf("Test %d: SUCCESS\n", test_no);
        printf("Infix:");
        bstree_apply_infix(root, applyf);
        printf("\nPrefix:");
        bstree_apply_prefix(root, applyf);
        printf("\nPostfix:");
        bstree_apply_postfix(root, applyf);
        bstree_destroy(root);
    } else {
        printf("Test %d: FAIL", test_no);
    }
}

void applyf(int item) {
    printf(" %d", item);
}

int cmpf(int a, int b) {
    int result;

    if (a < b)
        result = -1;
    else if (a == b)
        result = 0;
    else
        result = 1;

    return result;
}
