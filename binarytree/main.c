#include <stdio.h>
#include <stdlib.h>

struct tree {
    int x;
    struct tree *left;
    struct tree *right;
};

void add_tree(int *k, struct tree *t1) {
    static int ind = 0;
    if (t1 == NULL) {
        return;
    }
    add_tree(k, t1->left);
    k[ind++] = t1->x;
    add_tree(k, t1->right);
}

void is(int *k, struct tree *t2, int *fl, int size) {
    if (t2 == NULL) {
        return;
    }
    is(k, t2->left, fl, size);
    if (*fl == 0) {
        return;
    }
    int fl1 = 0;
    for (int i = 0; i < size; i++) {
        if (t2->x == k[i]) {
            fl1 = 1;
            break;
        }
    }
    *fl = fl1;
    is(k, t2->right, fl, size);
}

int is_subset(int size, struct tree *t1, struct tree *t2) {
    int k[size];
    add_tree(k, t1);
    int fl = 1;
    is(k, t2, &fl, size);
    return fl;
}

void print_tree(struct tree *t) {
    if (t == NULL) {
        return;
    }
    print_tree(t->left);
    printf("%d ", t->x);
    print_tree(t->right);
}

int main(void) {
    struct tree t1_5 = {5, 0, 0};
    struct tree t1_4 = {4, 0, &t1_5};
    struct tree t1_3 = {3, 0, &t1_4};
    struct tree t1_2 = {2, 0, &t1_3};
    struct tree t1 = {1, 0, &t1_2};

    struct tree t2_5 = {5, 0, 0};
    struct tree t2_4 = {4, 0, &t2_5};
    struct tree t2_3 = {13, 0, &t2_4};
    struct tree t2_2 = {2, 0, &t2_3};
    struct tree t2 = {1, 0, &t2_2};

    printf("%d", is_subset(5, &t1, &t2));
    return 0;
}