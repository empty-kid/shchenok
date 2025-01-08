#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int len(unsigned int a)
{
    int ln = 0;
    while (a>0){
        ln += 1;
        a = a/10;
    }
    return ln;
}
unsigned int reverse(unsigned int b)
{
    int ln = len(b);
    unsigned int c = 0;
    for (int i=0; i<ln; i++){
        int t1 = pow(10, i);
        int t2 = pow(10, ln-i-1);
        c += b / t1 % 10 * t2;
    }
    return c;
}
int polinom(unsigned int p)
{
    int ln = len(p);
    int fl = 1;
    for (int i=0; i<ln; i++){
        int t1 = pow(10, i);
        int t2 = pow(10, ln-i-1);
        if (p / t1 % 10 != p / t2 % 10){
            fl = 0;
            break;
        }
    }
    return fl;
}
int main(void)
{
    unsigned int m;
    int n;
    scanf("%u %d", &m, &n);
    for (int i=0; i<n; i++){
        m += reverse(m);
    }
    if (polinom(m)){
        printf("Yes\n%u", m);
    }else{
        printf("No");
    }
    return 0;
}
