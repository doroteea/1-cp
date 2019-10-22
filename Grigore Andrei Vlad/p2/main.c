#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,s;
    scanf("%f",&x);
    if(x<-2)
    {
        s=x*x-7*x+4;
    }
    else if(x==-2)
    {
        s=0;
    }
    else
    {
        s=x*x+5*x-2;
    }
    printf("%f",s);

    return 0;
}
