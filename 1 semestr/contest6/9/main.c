#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *a = fopen("input.bin", "rb");
    FILE *b = fopen("output.bin", "wb");
    int ln = 1;
    int fl = 100;
    int *c = malloc(sizeof(int) * 100);

    while (fread(c, sizeof(int), ln, a) == ln) {
        ln++;
        if (ln == fl) {
            fl *= 2;
            c = realloc(c, sizeof(int) * fl);
        }
    }

    ln--;
    int is_maxheap = 1;
    int is_minheap = 1;

    for (int i = 0; i < ln; i++) {
        if (2 * i + 1 < ln) {
            if (!(c[i] >= c[2*i+1])) {
                is_maxheap = 0;
            }
            if (!(c[i] <= c[i/2])) {
                is_minheap = 0;
            }
        }
        if (2 * i + 2 < ln) {
            if (!(c[i] >= c[2*i+2])) {
                is_maxheap = 0;
            }
            if (!(c[i] <= c[i/2])) {
                is_minheap = 0;
            }
        }
        if (!is_maxheap && !is_minheap) {
            break;
        }
    }

    int x;

    if (is_maxheap) {
        x = -1;
    }
    else if (is_minheap) {
        x = 1;
    }
    else {
        x = 0;
    }
    fwrite(&x, sizeof(int), 1, b);
    free(c);
    fclose(a);
    fclose(b);
    return 0;
}
