#include <stdio.h>
#include <stdlib.h>

struct tree {
    int key;
    struct tree *left;
    struct tree *right;
};

struct tree *add_tree(struct tree *head, short a[][3], int ind) {
    if (a[ind][1] == -1 && a[ind][2] == -1) {
        head = malloc(sizeof(struct tree));
        head->key = a[ind][0];
        head->left = NULL;
        head->right = NULL;
        return head;
    }
    head = malloc(sizeof(struct tree));
    head->key = a[ind][0];
    if (a[ind][1] > 0) {
        head->left = add_tree(head->left, a, a[ind][1]);
    }
    else {
        head->left = NULL;
    }
    if (a[ind][2] > 0) {
        head->right = add_tree(head->right, a, a[ind][2]);
    }
    else {
        head->right = NULL;
    }
    return head;
}

void print_tree(struct tree *t) {
    if (t == NULL) {
        return;
    }
    print_tree(t->left);
    printf("%d ", t->key);
    print_tree(t->right);
}

void winding(struct tree *t, int *max, int cur, int fl) {
    if (cur > *max) {
        *max = cur;
    }
    if (t->left != NULL) {
        if (fl == 1) {
            winding(t->left, max, cur, 1);
        }

        else {
            winding(t->left, max, cur + 1, 1);
        }
    }
    if (t->right != NULL) {
        if (fl == 2) {
            winding(t->right, max, cur, 2);
        }
        else {
            winding(t->right, max, cur + 1, 2);
        }
    }
}

int main(void) {
    short a[20240][3];
    int ind = 0;
    FILE *f = fopen("input.bin", "rb");
    while (fread(a[ind], sizeof(short), 3, f)) {
        ind += 1;
    }
    struct tree *head = NULL;
    head = add_tree(head, a, 0);
    struct tree *t = head;
    // print_tree(t);
    int max = 0;
    winding(head, &max, 0, 0);
    printf("%d\n", max);
    fclose(f);

    return 0;
}