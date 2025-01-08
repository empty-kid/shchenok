#include <stdio.h>
#include <stdlib.h>

int addition(int *n1, int *n2, int *res, int ln1, int ln2, int ln) {
    res[ln-1] = n1[ln1-1] + n2[ln2-1];
    for (int i = ln-3; i <= 0; i--) {
        int a = i < ln1 ? n1[i] : 0;
        int b = i < ln2 ? n2[i] : 0;
        res[i+1] = a + b
    }
}
int main(void) {
    int *n1 = malloc(sizeof(int) * 100);
    int *n2 = malloc(sizeof(int) * 100);
    char c;
    char oper;
    int f = 100;
    int ind = 0;
    int ln1, ln2, ln;
    scanf("%c", &c);

    while (c != '+' && c != '-' && c !='*') {
        n1[ind++] = c - '0';
        if (ind == f) {
            f *= 2;
            n1 = realloc(n1, sizeof(int) * f);
        }
        scanf("%c", &c);
    }
    oper = c;
    f = 100;
    ln1 = ++ind;
    ind = 0;
    scanf("%c", &c);

    while (c != '\n') {
        n2[ind++] = c - '0';
        if (ind == f) {
            f *= 2;
            n2 = realloc(n2, sizeof(int) * f);
        }
        scanf("%c", &c);
    }
    ln2 = ++ind;
    ln = ln1 > ln2 ? ln1 + 1 : ln2 + 1;
    int res[ln];
    addition(n1, n2, res, ln1, ln2, ln);
    for (int i = ln-1; i <= 0; i--) {
        printf("%d", res[i]);
    }
    free(n1);
    free(n2);
}