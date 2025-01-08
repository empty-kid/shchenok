#include <stdio.h>
#include <stdlib.h>

static int A;

static int *bless(int *ptr)
{
    if (*ptr > 0) return ptr;

    printf("%d\n", *ptr);
    exit(0);
}

static int *cursed(int E)
{
    int B = -2;
    extern int C;
    static int D = 4;
    int *ret = 0;
    if (E) {
        static int E = 5;
    } else {
        int C = -3;
        static int D = -4;
        ret = &D;
    }
    return bless(ret);
}

int C = 3;

int main(void)
{
    printf("%d\n", *cursed(A));
}