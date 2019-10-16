#include <stdio.h>
#include <stdlib.h>
///problema 3.5

int main()
{
    int x;
    printf("Dati x:");
    scanf("%d",&x);
    printf("x=%d\n",x);
    printf("f(x)=");
    if(x<-2)
    {
        printf("%d",x*x-7*x+4);
    }
    else if(x==-2)
    {
        printf("%d",0);
    }
    else
        printf("%d",x*x+5*x-2);


    return 0;
}
