///Find the greatest perfect square that is less than or equal to n. Then find the least prime number that is greater than or equal to n.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,n,foundPrime,nrDiv,j;
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        if(sqrt(i)==(int)sqrt(i))
        {
            printf("The greatest perfect square smaller than or equal to n is: %d \n",i);
            break;
        }
    }
    foundPrime=0;
    i=n;
    while(foundPrime==0)
    {
        nrDiv=0;
        if(i%2==0 || i<2)foundPrime=0;
        else
        {
            for(j=3;j*j<=i;j=j+2)
                if(i%j==0)nrDiv++;
            if(nrDiv==0)foundPrime=1;
        }
        i++;
    }
    printf("The smallest prime number greater than or equal to n is: %d ",i-1);
    return 0;
}
