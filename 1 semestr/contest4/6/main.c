#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int k;
    scanf("%d", &k);
    getchar();
    char s[k+1];
    fgets(s, k+1, stdin);
    if (s[strlen(s) - 1] == '\n') {
        s[strlen(s) - 1] = '\0';
    }
    int count = 0;

    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == ' ' && s[i-1] != ' ') {
            count++;
        }
    }
    count++;
    int delta = k - strlen(s) + count - 1;
    int b = delta / (count - 1);
    char prob[b+1];
    for (int i = 0; i < b; i++) {
        prob[i] = ' ';
    }

    prob[b] = '\0';
    int ind = 0;
    char *p = strtok(s, " ");

    while (p != NULL) {
        printf("%s", p);
        p = strtok(NULL, " ");
        if (p != NULL) {
            printf("%s", prob);
            if(ind < delta % (count - 1)) {
                printf(" ");
            }
            ind += 1;
        }
    }
    return 0;
}