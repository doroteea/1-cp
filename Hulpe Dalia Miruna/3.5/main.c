#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nr;
    scanf("%f",&nr);
    if(nr<-2)
    {
        printf("%f",nr*nr-7*nr+4);
    }
    else if(nr==-2)
    {
        printf("%f",0);
    }
    else
    {
        printf("%f",nr*nr+5*nr-2);
    }
    return 0;
}
