#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,ok,k;
    scanf("%d",&n);
    for(i=n; i>=2; i--)
    {
        if((int)sqrt(i)==sqrt(i))
        {
            printf("Cel mai mare patrat perfect este=%d\n",i);
            break;
        }

    }
    ok=1;
    i=n;
    while(ok==1)
    {
        k=1;
        for(j=2; j<=i/2; j++)
            if(i%j==0)
            {
                k=0;
            }
        if(k==1)
        {
            printf("Cel mai mic nr prim este=%d",i);
            ok=0;

        }
        i++;
    }
    return 0;
}
