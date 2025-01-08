#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double x, y, sum_x = 0, sum_y = 0;
    for (int i=1; i<=3; i++){
        scanf("%lf %lf/n", &x, &y);
        sum_x += x;
        sum_y += y;
    }
    printf("%.4f %.4f", sum_x / 3, sum_y / 3);
    return 0;
}
