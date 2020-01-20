#include <stdio.h>
#include <stdlib.h>


int isPrime(int x)
{
    for(int d=2; d<=x/2; d++)
    {
        if(x%d==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n,x;
    printf("Please insert the number n:\nn=");
    scanf("%d",&n);
    x=2;///We consider 2 as the minimum natural prime number
    while(x<=n)
    {
        if(isPrime(x)==1)
            printf("%d  ",x);
        x++;
    }
}
