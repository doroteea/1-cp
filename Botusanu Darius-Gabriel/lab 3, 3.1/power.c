#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double calaculatePower()
{
    double x, y;
    printf("Please insert a real number with double precision: ");
    scanf("%lf",&x);
    printf("\nPlease insert its power: ");
    scanf("%lf",&y);
    return pow(x,y);
}
