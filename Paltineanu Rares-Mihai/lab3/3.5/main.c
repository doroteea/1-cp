#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,f;

    scanf("%d",&x);

    if(x<-2)
        f=x*x-7*x+4;

    else

        if(x==-2)
            f=0;

            else
                if(x>-2)
                    f=x*x+5*x-2;
    printf("F is equal to:%d",f);
    return 0;
}

