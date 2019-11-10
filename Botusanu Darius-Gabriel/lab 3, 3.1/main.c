#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y,z;
    printf("Input 2 real numbers: ");
    scanf("%lf %lf", &x, &y);
    double pow(double, double);
    z=pow(x,y);
    printf("\n This is z: %lf", z);
    return 0;
}
/*It's bugging me that, whatever values I enter, the code returns z with the value 0.0000*/
