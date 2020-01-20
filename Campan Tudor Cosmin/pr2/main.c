#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,nrdiv;
    scanf("%d",&n);
    if(n==1)
        printf("1");
    for(i=2; i<=n; i++)
    {
        nrdiv=0;
        for(j=1; j<=i; j++)
        {

            if(i%j==0)
            {
                nrdiv++;
            }
        }
        if (nrdiv==2)


        {
            printf("%d ",i);
        }
    }
    return 0;
}

