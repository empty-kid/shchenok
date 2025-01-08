#include <stdio.h>
#include <string.h>

int pow(int n1, int c) {
    int t = n1;
    for (int i = 0; i < c - 1; i++) {
        n1 = n1 * t;
    }
    return n1;
}

char *reverse(char *str) {
    char g[100];
    int ind = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        g[ind++] = str[i];
    }
    g[ind] = '\0';
    strcpy(str, g);
    return str;
}

int decto3(char *str) {
    int p = 0;
    int ln = strlen(str);
    for (int i = 0; i < ln; i++) {
        p += (str[i] - '0') * (pow(3, ln - i - 1));
    }
    return p;
}

int main(void) {
    int n = 618527444;
    char s[100];
    int ind = 0;
    while (n > 0) {
        s[ind++] = ('0' + n % 3);
        n /= 3;
    }
    s[ind] = '\0';
    int a = 1;
    int b = 1;
    printf("%d\n", decto3("01121000"));
    printf("%d\n", decto3("0123456"));

    return 0;
}