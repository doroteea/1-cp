#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,i,j,nrDiv=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        nrDiv=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j == 0)
                nrDiv++;
        }
        if(nrDiv == 0)
            printf("%d ",i);
    }
    return 0;
}
