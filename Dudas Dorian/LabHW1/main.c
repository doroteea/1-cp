#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y,z,i;
    i=1;
    scanf("%lf,%lf",&x,&y);
    //z = pow(x,y);


    z=x;
    while (i<y)
    {
        z = z*x;
        i = i+1;
    }

    if (y==0)
    {
        z=1;
    }
    printf("%lf",z);
    return 0;
}
