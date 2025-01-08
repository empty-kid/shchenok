#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(sizeof(int) * 100);
    int fl = 100;
    int x;
    scanf("%d", &x);
    a[0] = x;
    scanf("%d", &x);
    int ind = 1;
    while (x != 0) {
        a[ind++] = x;
        if (ind == fl) {
            fl *= 2;
            a = realloc(a, sizeof(int) * fl);
        }
        scanf("%d", &x);
    }
    a = realloc(a, sizeof(int) * ind);
    // for (int i = 0; i < ind; i++) {
    //     printf("%d\n", a[i]);
    // }
    int step;
    scanf("%d", &step);
    int cur = 0;
    int count = 0;
    while (cur != ind) {
        int fl = 0;
        if (cur + step >= ind) {
            count += 1;
            break;
        }
        else {
            for (int i = step + cur; i > cur; i--) {
                if (a[i] < a[i + 1]) {
                    cur += i;
                    count += 1;
                    fl = 1;
                }
            }
            if (fl == 0) {
                printf("%d", 1);
                return 0;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
