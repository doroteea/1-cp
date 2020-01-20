#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i,ok=0,j,nrDiv;
    scanf("%d",&n);
    for(i=n; i>0; i--)
    {
        if(sqrt(i)*sqrt(i) == i)
        {
            printf("%d\n",i);
            break;
        }
    }
    i=n;
    while(ok==0)
    {
        nrDiv=0;
        for(j=2; j<sqrt(i); j++)
        {
            if(i%j==0)
                nrDiv++;
        }
        if(nrDiv == 0)
        {
            printf("%d",i);
            ok=1;
        }
        else
            i++;
    }
    return 0;
}
