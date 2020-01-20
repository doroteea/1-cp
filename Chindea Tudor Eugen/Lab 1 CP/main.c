#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    scanf("%d", &x);
    if(x<-2)
    {
        y=x*x-7*x+4;
    }
    else if(x==-2)
    {
        y=0;
    }
    else
    {
        y=x*x+5*x-2;
    }

    printf("f=%d",y);
    return 0;
}
