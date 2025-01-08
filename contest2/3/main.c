#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &m);
    int B[m];
    for (int i=0; i<m; i++){
        scanf("%d", &B[i]);
    }
    int R[n+m];
    int ind = 0;
    for (int i=0; i < n || i < m; i++){
        if (i<n){
            R[ind++] = A[i];
        }
        if (i<m){
            R[ind++] = B[i];
        }
    }
    for (int i=0; i<(n+m); i++){
        printf("%d ", R[i]);
    }
    return 0;
}
