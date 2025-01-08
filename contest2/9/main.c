#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    int X[m];
    for (int i=0; i<m; i++){
        scanf("%d", &X[i]);
    }
    for (int i=m-1; i>=0; i--){
        int sum = A[n-1];
        for (int j=n-2; j>=0; j--){
            sum = sum*X[i] + A[j];
        }
        printf("%d ", sum);
    }
    return 0;
}
