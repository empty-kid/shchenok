#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[2001];
    scanf("%2001s", s);
    char *p;
    unsigned n1, n2;
    int ind = 0;

    while (ind < strlen(s)) {
        if (s[ind] >= '0' && s[ind] <= '9'){
            n1 = strtol(s+ind, &p, 10);
            if (p[1] >= '0' && p[1] <= '9') {
                n2 = strtol(p+1, NULL, 10);
                switch (p[0]) {
                    case '+':
                        if (abs(n1 + n2) <= 120000) {
                            printf("%d + %d = %d\n", n1, n2, n1+n2);
                        }
                        break;
                    case '-':
                        if (abs(n1 - n2) <= 120000) {
                            printf("%d - %d = %d\n", n1, n2, n1-n2);
                        }
                        break;
                    case '*':
                        if (abs(n1 * n2) <= 120000) {
                            printf("%d * %d = %d\n", n1, n2, n1*n2);
                        }
                        break;
                    case '/':
                        if (n2) {
                            if (abs(n1 / n2) <= 120000) {
                                printf("%d / %d = %d\n", n1, n2, n1/n2);
                            }
                        }
                        break;
                    default: break;
                }
            }
            if(!n1) {
                ind++;
            }

            while (n1 > 0) {
                ind++;
                n1 /= 10;
            }

        }else {
            ind++;
        }
    }

    return 0;
}
