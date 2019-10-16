#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,ok;
    scanf("%d",&n);
    for(i=2; i<=n; i++)
    {
        ok=1;
        for(j=2; j<=i/2; j++)
            if(i%j==0)
            {
                ok=0;
            }
        if(ok==1)
        {
            printf("%d\n",i);
        }

    }
    return 0;
}
