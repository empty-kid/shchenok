#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int unsigned a, b;
    scanf("%u", &a);
    b = (a ^ 0xFF000000);
    printf("%u", b);
    return 0;
}
