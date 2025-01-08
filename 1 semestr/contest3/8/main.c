#include <stdio.h>
#include <stdlib.h>

int med(int *p, int c){
    if (p[c] >= *(p + c + 1) && *(p + c) <= *(p + c + 2)){
        return *(p + c);
    }else if (*(p + c) <= *(p + c + 1) && *(p + c + 1) <= *(p + c + 2)){
        return *(p + c + 1);
    }else if(*(p + c) >= *(p + c + 2) && *(p + c) <= *(p + c + 1)){
        return *(p + c);
    }else if(*(p + c + 1) >= *(p + c + 2) && *(p + c) >= *(p + c + 1)){
        return *(p + c + 1);
    }
    else{
        return *(p + c + 2);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    while (n>1){
        for (int i=0; i<n-2; i++){
            int b = med(a, i);
            a[i] = b;
        }
        n -= 2;
    }
    printf("%d", a[0]);
    return 0;
}
