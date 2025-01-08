#include <stdio.h>
#include <string.h>

int towns(char (*s)[21], int n, int *used, char a) {
    int max_ln = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i] && s[i][0] == a) {
            used[i] = 1;
            int ln = 1 + towns(s, n, used, s[i][strlen(s[i]) - 1]);
            used[i] = 0;
            if (ln > max_ln) {
                max_ln = ln;
            }
        }
    }
    return max_ln;
}

int main(void) {
    int n;
    scanf("%d", &n);
    char s[10][21];
    int used[10] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%20s", s[i]);
    }

    int max_ln = 0;
    int mx[10];
    for (int i = 0; i < n; i++) {
        used[i] = 1;
        int ln = 1 + towns(s, n, used, s[i][strlen(s[i]) - 1]);
        used[i] = 0;
        mx[i] = ln;
        if (ln > max_ln) {
            max_ln = ln;
        }
    }

    printf("%d\n", max_ln);

    for (int i = 0; i < n; i++) {
        if (mx[i] == max_ln) {
            printf("%s\n", s[i]);
        }
    }

    return 0;
}