#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("zxc");
    int a, b, min, max;
    scanf("%d", &a);
    scanf("%d",&b);
    min = max = b;
    for (int i=1; i<=a-1; i++){
        scanf("%d", &b);
        if(b<min){
            min = b;

        }
        if(b>max){
            max = b;
        }
    }
    printf("%d", max-min);
    return 0;
}
