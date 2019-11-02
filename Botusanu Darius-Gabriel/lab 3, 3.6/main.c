#include <stdio.h>
#include <stdlib.h>
/*Alex, I think I may have finally cotton on to the pleasure of programming! Thanks for your support!*/

int main()
{
    float x, d, m, s;
    printf("Please, input your angle in radians and press ENTER:\n");
    scanf("%f", &x);
    d=(x*180)/3.14;
    m=60*d;
    s=60*m;
    printf("This is your angle in degrees: %f \n", d);
    printf("This is your angle in minutes: %f \n", m);
    printf("This is your angle in seconds: %f \n", s);
    return 0;
}
