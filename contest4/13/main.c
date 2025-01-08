#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prefix_function(char *s, int *pi) {
    int ln = strlen(s);
    pi[0] = 0;

    for (int i = 1; i < ln; i++) {
        if (s[i] == s[pi[i - 1]]) {
            pi[i] = pi[i-1] + 1;
        }else {
            int j = pi[i-1];

            while (j > 0 && s[j] != s[i]) {
                j = pi[j - 1];
            }

            if (s[j] == s[i]){
                pi[i] = j + 1;
            }else {
                pi[i] = 0;
            }
        }
    }

}

int main(void) {
    char s[1000001];
    scanf("%1000000s", s);
    int ln = strlen(s);
    int pi[ln];
    prefix_function(s, pi);
    int per = pi[ln-1];

    while (per) {
        printf("%d ", ln - per);
        per = pi[per-1];
    }

    if (ln) {
        printf("%d", ln);
    }
    return 0;
}