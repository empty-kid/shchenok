#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void biss(double s1, double s2, double x1, double y1, double x2, double y2, double *s_){
    double m = s1  / s2;
    double x3 = (x1+x2*m)/(1+m);
    double y3 = (y1+y2*m)/(1+m);
    *s_ = x3;
    *(s_ + 1) = y3;
}
int main(void)
{
    double x[3];
    double y[3];
    double acb[2];
    double bac[2];
    double abc[2];
    for (int i=0; i<3; i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }
    double ab = pow(pow(x[0]-x[1], 2) + pow(y[0]-y[1], 2), 0.5);
    double ac = pow(pow(x[0]-x[2], 2) + pow(y[0]-y[2], 2), 0.5);
    double bc = pow(pow(x[1]-x[2], 2) + pow(y[1]-y[2], 2), 0.5);
    biss(ac, bc, x[0], y[0], x[1], y[1], acb);
    biss(ab, ac, x[1], y[1], x[2], y[2], bac);
    biss(ab, bc, x[0], y[0], x[2], y[2], abc);
    printf("%.5f %.5f\n", acb[0], acb[1]);
    printf("%.5f %.5f\n", bac[0], bac[1]);
    printf("%.5f %.5f\n", abc[0], abc[1]);
    return 0;
}
