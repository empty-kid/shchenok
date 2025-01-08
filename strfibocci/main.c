#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fibocci(char *s) {
    int a = 1;
    int b = 1;
    int ind = 0;
    int count = 1;
    int len = strlen(s);
    char *res = calloc(len, sizeof(char));
    while (ind < len) {
        if (count % 2 == 0) {
            strncat(res, s+ind, a);
        }
        ind += a;
        int c = b;
        b += a;
        a = c;
        count++;
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
