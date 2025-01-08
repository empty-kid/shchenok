#include <stdio.h>

int main(void) {
    unsigned n;
    unsigned k = 0;
    unsigned bit;
    scanf("%u", &n);
    for (int i = 0; i < 32; i+=8) {
        bit = (n >> i) & 0x000000ff;
        k += bit << (32 - i - 8);
    }
    printf("%u", k);
    return 0;
}