#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int val;
    struct list *next;
};

int compare(struct list *a, struct list *b) {
    if (a->val == b->val) {
        return 0;
    }
    if (a->val > b->val) {
        return 1;
    }
    if (a->val < b->val) {
        return -1;
    }
}

int main(void) {
    struct list *head = malloc(sizeof(struct list));
    head->val = 2;
    head->next = malloc(sizeof(struct list));
    head->next->val = 4;
    head->next->next = malloc(sizeof(struct list));
    head->next->next->val = 1;
    head->next->next->next = malloc(sizeof(struct list));
    head->next->next->next->val = 3;
    head->next->next->next->next = NULL;



    qsort(head, 4, sizeof(struct list), compare);
    printf("%d\n", head->val);
    return 0;
}