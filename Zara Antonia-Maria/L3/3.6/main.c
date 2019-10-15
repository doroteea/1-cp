#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x,degrees;
    printf("Input the angle in radians: ");
    scanf("%f",&x);
    printf("The angle %f in degrees is %f \n",x,x*180/M_PI);
    printf("The angle %f in minutes is %f \n",x,x*180/M_PI*60);
    printf("The angle %f in seconds is %f \n",x,x*180/M_PI*3600);
    return 0;
}
