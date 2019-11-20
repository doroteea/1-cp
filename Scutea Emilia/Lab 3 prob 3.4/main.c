#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=2,d,ok;
    printf("Give n:");
    scanf("%d",&n);
    if(n<2)
    {
        printf("There are no prime numbers less than or equal to n\n");
    }
    else
    {
        printf("The prime numbers less than or equal to n are:");
        while (i<=n)
        {
            ok=1;
            for(d=2; d<=i/2; d++)
                if(i%d==0)
                {
                    ok=0;
                    break();
                }
            if(ok==1)
                printf("%d ",i);
            i++;
        }
    }

    return 0;
}
