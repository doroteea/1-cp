#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,n,j,a;
    scanf("%d",&n);
    N=0;
    for(i=0; i<n; i++)
    {
        a=i+1;
        for(j=0; j<(a/2); j++)
        {
            if(a%(j+1)==0)
            {
                N=N+1;
            }
        }
        if(N==1)
        {
            printf("%d ",a);
        }
        N=0;

    }
    return 0;
}
