#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    short unsigned a, a_t = 0;
    scanf("%hx", &a);
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            int b = (a >> (i*4 + j)) & 1;
            a_t = a_t | (b << (i+j*4));
        }
    }
    printf("%04hx", a_t);
}
