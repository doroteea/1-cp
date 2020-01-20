#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,rez;
    scanf("%d",&x);

    if(x<-2)
    {
        rez=x*x-7*x+4;
        printf("%d",rez);
    }
    else if (x==-2)
    {
        printf("%d",0);
    }
    else
    {
        rez=x*x+5*x-2;
        printf("%d",rez);
    }
    return 0;
}
