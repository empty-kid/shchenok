#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next, *prev;
};

struct list *add(struct list *q, int x) {
    if (q == NULL) {
        q = malloc(sizeof(struct list));
        q->prev = NULL;
        q->next = NULL;
        q->data = x;
        return q;
    }
    else {
        struct list *p = malloc(sizeof(struct list));
        q->next = p;
        p->prev = q;
        p->next = NULL;
        p->data = x;
        return p;
    }
}

struct list *qsort(struct list *head, int size) {
    if (head->next == NULL || head == NULL) {
        return head;
    }
    
}

int main(void) {
    FILE *a = fopen("input.txt", "r");
    int x;
    struct list *head = NULL;
    struct list *q;
    while (fscanf(a, "%d", &x) != EOF) {
        if (head == NULL) {
            head = add(head, x);
            q = head;
        }
        else {
            q = add(q, x);
        }
    }

    fclose(a);
    return 0;
}
