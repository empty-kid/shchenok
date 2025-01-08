#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibocci(char *s) {
    int a = 0;
    int b = 1;
    int c;
    int ind = 0;
    int len = strlen(s);
    char *res = calloc(len * 2, sizeof(char));
    while (ind < len) {
        if (ind == a) {
            strncat(res, s+ind, 1);
            strncat(res, " ", 1);
            c = b;
            b += a;
            a = c;
            if (a == b) {
                c = b;
                b += a;
                a = c;
            }
        }
        else {
            strncat(res, s+ind, 1);
        }
        ind++;
    }
    res = realloc(res, (strlen(res) + 1) * sizeof(char));
    free(s);
    return res;
}

int main(void) {
    char *s = malloc(sizeof(char) * 100);
    fgets(s, 100, stdin);
    s[strlen(s) - 1] = '\0';
    s = fibocci(s);
    printf("%s\n", s);
    return 0;
}