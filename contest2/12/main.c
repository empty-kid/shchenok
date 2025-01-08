#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int A[8], B[8];
    unsigned mx_a=0, mx_b = 0;
    for (int i=0; i<8; i++){
        scanf("%u", &A[i]);
        if(A[i] > mx_a){
            mx_a = A[i];
        }
    }
    for (int i=0; i<8; i++){
        scanf("%u", &B[i]);
        if(B[i] > mx_b){
            mx_b = B[i];
        }
    }
    if (mx_a == mx_b){
        int sum = 0;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (A[i] >= B[j]){
                    sum += B[j];
                }else{
                    sum += A[i];
                }
            }
        }
        printf("%d", sum);}
    else{
        printf("%d", -1);
    }
    return 0;
}
