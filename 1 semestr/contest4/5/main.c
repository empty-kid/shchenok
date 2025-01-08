#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char w[81];
    scanf("%80s", w);
    int ln = strlen(w);
    n = n % ln;
    for (int i = n; i < ln; i++) {
        printf("%c", *(w+i));
    }
    for (int i = 0; i < n; i++) {
        printf("%c", *(w+i));
    }
    return 0;
}