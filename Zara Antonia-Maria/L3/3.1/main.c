#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y,z;
    scanf("%lf", &x);
    scanf("%lf", &y);
    z=pow(x,y);
    printf("%lf",z); /// am incercat sa dau printf direct cu pow in el dar nu m-am prins cum :(
    return 0;
}
