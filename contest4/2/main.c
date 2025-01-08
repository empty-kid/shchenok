#include <stdio.h>
#include <string.h>
int is(char b) {
    return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' || b == 'y' ||
           b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U' || b == 'Y';
}
int count(char* str) {
    int count = 0;
    if (is(*str)) {
        count++;
    }
    str++;

    while (*str) {
        if (is(*str) && !is(*(str - 1))) {
            count++;
        }
        str++;
    }

    return count;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[10000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    char str[102];
    fgets(str, 102, stdin);

    for (int i = 0; i < n; i++) {
        fgets(str, 102, stdin);
        int c = count(str);
        if (c == a[i]) {
            printf("%s", str);
        }
    }

    return 0;
}