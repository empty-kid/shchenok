#include <stdio.h>
#include <stdlib.h>

void sums(int *a_, int n, int index, int sum, int *m_) {
    *(m_+sum) += 1;
    for (int i = index; i < n; i++) {
        sums(a_, n, i + 1, sum + *(a_+i), m_);
    }
}

int main(void) {
    int sum = 0;
    int mxsums[1401]={0};
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    sums(a, n, 0, 0, mxsums);
    for (int i=sum/2; i>=0; i--){
        if (mxsums[i]>1){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
