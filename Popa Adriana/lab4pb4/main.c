#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,prim,d;
    printf("introduce n:");
    scanf("%d",&n);
    printf("The prime numbers smaller than n are:\n");
    x=2;
    while(x<n)
    {
        prim=1;
        if(x%2==0&x!=2)
            prim=0;
        for(d=3; d<=sqrt(x); d=d+2)
            if(x%d==0)
                prim=0;
        if(prim==1)
            printf("%d , ",x);
        x++;
    }
    return 0;
}
