#include <stdio.h>
#include <stdlib.h>

int main()
{
    double x;
    scanf("%f", &x);

    if (x<-2)
    {
        printf("%f", x*x-7*x+4);
    }
    else if (x==-2)
    {
        printf("0");
    }
    else
    {
        printf("%f", x*x+5*x-2);
    }
    return 0;
}
