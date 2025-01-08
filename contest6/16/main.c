#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};


struct list *add(struct list *p, int x) {
    if (p == NULL) {
        p = malloc(sizeof(struct list));
        p->data = x;
        p->next = NULL;
        return p;
    }
    else {
        struct list *q = malloc(sizeof(struct list));
        p->next = q;
        q->data = x;
        q->next = NULL;
        return q;
    }
}

void merge(struct list *first, struct list *second, struct list **res) {
    struct list *p;
    *res = NULL;
    if (first == NULL) {
        *res = second;
        return;
    }
    if (second == NULL) {
        *res = first;
        return;
    }
    if (first->data < second->data){
        *res = first;
        first = first->next;
    }
    else {
        *res = second;
        second = second->next;
    }
    p = *res;

    while (first && second) {
        if (first->data < second->data) {
            (*res)->next = first;
            first = first->next;
        }
        else {
            (*res)->next = second;
            second = second->next;
        }
        *res = (*res)->next;
    }

    while (first) {
        (*res)->next = first;
        *res = (*res)->next;
        first = first->next;
    }
    while (second) {
        (*res)->next = second;
        *res = (*res)->next;
        second = second->next;
    }
    *res = p;
}

void split(struct list *head, struct list **l, struct list **r, int size) {
    if (head == NULL || head->next == NULL) {
        *l = head;
        *r = NULL;
        return;
    }
    struct list *q = head;
    *l = q;
    for(int i = 1; i < size / 2; i++)
        q = q->next;
    *r = q->next;
    q->next = NULL;
}

void mergeSort(struct list **head, int size) {
    struct list *l = NULL;
    struct list *r = NULL;
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    split(*head, &l, &r, size);
    mergeSort(&l, size / 2);
    mergeSort(&r, (size + 1) / 2);
    merge(l, r, head);
}

int main(void) {
    FILE *a = fopen("input.txt", "r");
    FILE *b = fopen("output.txt", "w");
    struct list *head = NULL;
    struct list *q = head;
    int x;
    int size = 0;


    while (fscanf(a, "%d", &x) != -1) {
        if (size == 0) {
            head = add(head, x);
            q = head;
        }
        else {
            q = add(q, x);
        }
        size++;
    }

    mergeSort(&head, size);
    q = head;

    for(int i = 0; i < size; ++i) {
        fprintf(b, "%d ", q->data);
        q = q->next;
    }

    q = head;
    struct list *p;

    while (q) {
        p = q;
        q = q->next;
        free(p);
    }

    fclose(a);
    fclose(b);
    return 0;
}