#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, b;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n; i++){
        A[i] = 0;
    }
    for (int i=0; i<n; i++){
        scanf("%d", &b);
        if(b>n || b<1 || A[b-1]!=0){
            printf("No");
            return 0;
        }
        A[b-1] = 1;
    }
    printf("Yes");
    return 0;
}
