#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    unsigned r;
    scanf("%d", &n);
    scanf("%u", &r);
    unsigned A[n];
    A[0] = r;
    for (int i=1; i<n; i++){
        scanf("%u", &A[i]);
        r = r ^ A[i];
    }
    unsigned r1 = r;
    for (int i=0; i<16; i++){
        unsigned c = (r >> i) & 1;
        if (c == 1){
            for (int j=0; j<n; j++){
                if (((A[j]>>i) & 1) == 0){
                    r1 ^= A[j];
                }
            }
            break;
        }
    }
    r1<=(r^r1)?printf("%u %u", r1, r1^r):printf("%u %u", r1^r, r1);
    return 0;
}
