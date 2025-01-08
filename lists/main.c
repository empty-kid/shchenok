#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

void max_list(struct list *start, struct list *end, int *max, int cur, struct list **s, struct list **e) {
    if (cur > *max) {
        *max = cur;
        *s = start;
        *e = end;
    }
    if (end -> next != NULL) {
        max_list(start, end->next, max, cur + end->next->data , s, e);
        max_list(end, end->next, max, end->next->data, s, e);
    }
}

struct list *transform(struct list *head) {
    int max = -9999999;
    struct list *s = head;
    struct list *e = head;
    max_list(head, head, &max, head->data, &s, &e);
    if (s != head) {
        struct list *q = s->next;
        s->next = e->next;
        e->next = head;
        return q;
    }
    return head;

}

int main(void) {
    struct list *head = malloc(sizeof(struct list));
    head->data = -1;
    head->next = malloc(sizeof(struct list));
    head->next->data = -2;
    head->next->next = malloc(sizeof(struct list));
    head->next->next->data = 1;
    head->next->next->next = malloc(sizeof(struct list));
    head->next->next->next->data = 2;
    head->next->next->next->next = malloc(sizeof(struct list));
    head->next->next->next->next->data = -1;
    head->next->next->next->next->next = NULL;
    head = transform(head);
    printf("%d\n", head->next->next->next->next->data);

    return 0;
}