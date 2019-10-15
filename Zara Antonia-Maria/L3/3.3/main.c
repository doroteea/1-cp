#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,sinus,cosinus,tangenta,rad;
    printf("Input the angle x in degrees: ");
    scanf("%lf", &x);
    rad=x*M_PI/180;
    sinus=sin(rad);
    cosinus=cos(rad);
    tangenta=tan(rad);
    printf("sin of x is %lf \n",sinus);
    printf("cos of x is %lf \n",cosinus);
    printf("tan of x is %lf \n",tangenta);
    return 0;
}
