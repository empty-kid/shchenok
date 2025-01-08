#include <stdio.h>
#include <limits.h>

struct list {
    int key;
    struct list *next;
    struct list *sublist_head;
};

void min_len(struct list *t, int *ln, int cur_len) {
    if (t -> next == NULL) {
        cur_len++;
        if (cur_len < *ln) {
            *ln = cur_len;
        }
    }
    if (t -> next != NULL) {
        min_len(t->next, ln, cur_len + 1);
    }
    if (t -> sublist_head != NULL) {
        min_len(t->sublist_head, ln, 0);
    }
}

void max_br(struct list *t, int ln, int cur_len, int *max, int br) {
    if (t -> next == NULL) {
        cur_len++;
        if (cur_len == ln) {
            if (br > *max) {
                *max = br;
            }
        }
    }
    if (t -> next != NULL) {
        if (br < t->next->key) {
            max_br(t->next, ln, cur_len + 1, max, t->next->key);
        }
        else {
            max_br(t->next, ln, cur_len + 1, max, br);
        }
    }
    if (t -> sublist_head != NULL) {
        max_br(t->sublist_head, ln, 0, max, t->sublist_head->key);
    }
}

int examine(struct list *gerland) {
    if (gerland == NULL) {
        return -1;
    }
    int ln = INT_MAX;
    min_len(gerland, &ln, 0);
    int max = 0;
    max_br(gerland, ln, 0, &max, gerland->key);
    return max;
}

int main(void) {
    struct list part4[] = {{4, &part4[1], NULL}, {4, &part4[2], NULL}, {4, NULL, NULL}};
    struct list part3[] = {{3, &part3[1], NULL}, {3, NULL, NULL}};
    struct list part2[] = {{2, &part2[1], NULL}, {2, &part2[2], &part3[0]}, {2, NULL, NULL}};
    struct list part1[] = {{1, &part1[1], &part2[0]}, {1, &part1[2], NULL}, {1, NULL, &part4[0]}};
    struct list *example = &part1[0];
    printf("%d", examine(example));
    return 0;
}