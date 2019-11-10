#include <stdio.h>
#include <stdlib.h>
/*Thanks for your time Alex, I am really grateful for your help */

int main()
{
    double r, n, PI, sine, cosine, tg;
    PI=3.14;
    printf("Please input your angle in radians: ");
    scanf("%lf", &r);
    double sin(double r);
    double cos(double r);
    sine= sin(r);
    cosine= cos(r);
    tg=sin/cos;
    n=(r*180)/PI;
    printf("\n This is your angle in degrees: %lf", n);
    printf("\n sin= %lf", sine);
    printf("\n cos= %lf", cosine);
    printf("\n tg= %lf", tg);
    return 0;
}






