#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x,y,z;
    printf("Please insert x:\nx=");
    scanf("%lf",&x);
    printf("Please insert y:\ny=");
    scanf("%lf",&y);
    z=pow(x,y);
    printf("z=%lf",z);
    return 0;
}
