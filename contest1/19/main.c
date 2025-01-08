#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int a11, a12, a21, a22, b1, b2;
    unsigned int x = 0, y = 0;
    scanf("%u %u/n", &a11, &a12);
    scanf("%u %u/n", &a21, &a22);
    scanf("%u %u", &b1, &b2);
    for (int i=1; i<=32; i++){
        unsigned int b_a11 = (a11 >> i) & 1;
        unsigned int b_a12 = (a12 >> i) & 1;
        unsigned int b_a21 = (a21 >> i) & 1;
        unsigned int b_a22 = (a22 >> i) & 1;
        unsigned int b_b1 = (b1 >> i) & 1;
        unsigned int b_b2 = (b2 >> i) & 1;
        int fl = 0;
        for (int b_x=0; b_x<=1; b_x++){
            for (int b_y=0; b_y<=1; b_y++){
                if (((b_a11 & b_x) ^ (b_a12 & b_y)) == b_b1){
                    if (((b_a21 & b_x) ^ (b_a22 & b_y)) == b_b2){
                        fl = 1;
                        x = x | (b_x << i);
                        y = y | (b_y << i);
                        break;
                    }
                }
            }
            if (fl == 1){
                break;
            }
        }
        if (fl == 0){
            printf("No");
            return 0;
        }

    }
    printf("Yes\n");
    printf("%u %u", x, y);


    return 0;
}
