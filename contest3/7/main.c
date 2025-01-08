#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double area(int i, int j, int k, int *x_, int *y_){
    int x1 = *(x_+i);
    int x2 = *(x_+j);
    int x3 = *(x_+k);
    int y1 = *(y_+i);
    int y2 = *(y_+j);
    int y3 = *(y_+k);
    return 0.5 * abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));

}

int main(void)
{
    int n;
    double mx = 0;
    scanf("%d", &n);
    int x[n], y[n];
    for (int i=0; i<n; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i=0; i<n-2; i++){
        for (int j=i+1; j<n-1; j++){
            for (int k=j+1; k<n; k++){
                double sq = area(i, j, k, x, y);
                mx = mx >= sq ? mx : sq;
            }
        }
    }
    printf("%.6f", mx);
    return 0;
}
