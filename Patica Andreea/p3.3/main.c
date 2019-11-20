#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    scanf("%f", &x);
    x=x*acos(-1)/180;
    printf("%f %f %f", sin(x), cos(x), sin(x)/cos(x));

    return 0;
}
