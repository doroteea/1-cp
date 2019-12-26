#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfectSquare(int n)
{
    if(sqrt(n)*sqrt(n)==n)
        return 1;
    return 0;
}

int greatestPerfectSquare(int n)
{
    while(perfectSquare(n)==0)
    {
        n--;
    }
    return n;
}

int prime(int n)
{
    for(int d=2;d<=n/2;d++)
    {
        if(n%d==0)
            return 0;
    }
    return 1;
}


int leastPrimeNumber(int n)
{
    while(prime(n)==0)
    {
        n++;
    }
    return n;
}

int main()
{
    int n;
    printf("Please insert the number n:\nn=");
    scanf("%d",&n);
    printf("The greatest perfect square less or equal to %d is %d.\n",n,greatestPerfectSquare(n));
    printf("The least prime number greater or equal to %d is %d.\n",n,leastPrimeNumber(n));

}
