/*Write a program which reads a real number x, representing a measurement for an angle in Radians,
and then converts it to degrees, minutes, and seconds
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
int main()
{

    float rad,dgr,min,sec;
    scanf("%f", &rad);
    dgr=rad*180/PI;
    min=(dgr-floor(dgr))*60;
    dgr=floor(dgr);
    sec=(min-floor(min))*60;
    min=floor(min);
    printf(("degrees: %f; minutes: %f; seconds:%f"), dgr, min, sec);
    return 0;
}
