#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y, d;
    scanf("%d %d", &x, &y);
    d = abs(abs(x) - abs(y));
    if (abs(x) > abs(y)){
        d = abs(y)*2 + d*2 - d%2;
    }else{
        d = abs(x)*2 + d*2 - d%2;
    }
    printf("%d", d);
    return 0;
}
