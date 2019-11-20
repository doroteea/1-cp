#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
int main()
{
    float rad,dgr;
    scanf("%f", &dgr);
    rad=dgr*PI/180;
    printf("%The sin value is %lf\n",sin(rad));
    printf("%The cos value is %lf\n",cos(rad));
    printf("The tan value is %lf",sin(rad)/cos(rad));
    return 0;
}
