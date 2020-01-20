#include <stdio.h>
#include <stdlib.h>
int n,var,prime,i;
int main()
{
    scanf("%d",&n);
    if(n<2)
    {
        printf("no prime numbers");
    }
    else
    {
        printf("2");
        for(var=3; var<=n; var=var+2)
        {
            prime=1;
            i=3;
            while(i*i<=var)
            {
                if(var%i==0)
                {
                    prime=0;
                }
                i=i+2;
            }
            if(prime==1)
            {
                printf(" %d",var);
            }
        }
    }
    return 0;
}
