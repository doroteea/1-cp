#include <stdio.h>

int main()
{
    int i,n,j,ok=0;

    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("All prime numbers from 1 to %d are:\n",n);
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                ok=1;

            }
        }
        if(ok==0)
        {
            printf("%d ",i);
        }
    }

    return 0;
}

