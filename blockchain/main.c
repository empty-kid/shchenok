#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct SystemUnit {
    int id;
    int left_id;
    int right_id;
    uint32_t config;
};

struct SystemStructure {
    struct SystemUnit unit;
    struct SystemStructure *left;
    struct SystemStructure *right;
};

struct SystemStructure *add_tree(struct SystemStructure *root, struct SystemUnit *k, int ind, int size) {
    struct SystemUnit z = {0, 0, 0, 0};
    for (int i = 0 ; i < size; i++) {
        if (k[i].id == ind) {
            z = k[i];
            break;
        }
    }
    if (z.left_id == 0 && z.right_id == 0) {
        root = malloc(sizeof(struct SystemStructure));
        root->unit = z;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    root = malloc(sizeof(struct SystemStructure));
    root->unit = z;
    if (z.left_id != 0) {
        root->left = add_tree(root->left, k, root->unit.left_id, size);
    }
    else {
        root->left = NULL;
    }
    if (z.right_id != 0) {
        root->right = add_tree(root->right, k, root->unit.right_id, size);
    }
    else {
        root->right = NULL;
    }
    return root;
}

void output(struct SystemStructure *root) {
    if (root == NULL) {
        return;
    }
    printf("%d %d %d %u\n", root->unit.id, root->unit.left_id, root->unit.right_id, root->unit.config);
    output(root->left);
    output(root->right);
}

int main(void) {
    FILE *f = fopen("input.bin", "rb");
    struct SystemUnit k[1000];
    int ln = 0;
    while (fread(&k[ln], sizeof(struct SystemUnit), 1, f)) {
        ln++;
    }
    struct SystemStructure *root = NULL;
    root = add_tree(root, k, 1, ln);
    output(root);
    fclose(f);
    return 0;
}