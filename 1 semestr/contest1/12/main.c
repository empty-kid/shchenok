#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b, m1, m2, m3;
    scanf("%d", &a);
    scanf("%d %d %d", &m1, &m2, &m3);
    if (m1 < m2){
        m2 = m1 + m2;
        m1 = m2 - m1;
        m2 = m2 - m1;
    }
    if (m1 < m3){
        m3 = m1 + m3;
        m1 = m3 - m1;
        m3 = m3 - m1;
    }
    if (m2 < m3){
        m3 = m2 + m3;
        m2 = m3 - m2;
        m3 = m3 - m2;
    }
    for (int i=1; i<=a-3; i++){
        scanf("%d", &b);
        if (b > m1){
            m3 = m2;
            m2 = m1;
            m1 = b;
        }else if(b>m2){
            m3 = m2;
            m2 = b;
        }else if(b>m3){
            m3 = b;
        }
    }
    printf("%d %d %d", m1, m2, m3);
    return 0;
}
