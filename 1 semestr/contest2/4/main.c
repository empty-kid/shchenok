#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, sum=0, b;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    for (int i=0; i<n; i++){
        scanf("%d", &b);
        if (A[i] >= b){
            sum += A[i];
        }else{
            sum += b;
        }
    }
    printf("%d", sum);
    return 0;
}
