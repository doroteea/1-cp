#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    float t;
    printf("Input your real value: ");
    scanf("%f", &x);
    if(x<-2)
        {
            t=x*x-7*x+4;
        }
    if(x==-2)
        {
            t=0;
        }
    if(x>-2)
        {
            t=x*x+5*x-2;
        }
    printf("f(x)= %f \n", t);
    return 0;
}
