#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, count=0;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if((i+j)%2==0 && (A[i]+A[j])%2==0){
                int k = (i+j) / 2;
                if (A[k] == (A[i] + A[j])/2){
                    count ++;
                }
            }
        }
    }
    printf("%d", count);
    return 0;
}
