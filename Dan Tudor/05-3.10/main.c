#include <stdio.h>
#include <stdlib.h>

void nrOfBacknotes(int n, int *nr)
{
    if(n/500 > 0)
    {
        *nr = *nr+n/500;
        n = n%500;
    }
    if(n/200 > 0)
    {
        *nr = *nr+n/200;
        n=n%200;
    }
    if(n/100 > 0)
    {
        *nr = *nr+n/100;
        n = n%100;
    }
    if(n/50 > 0)
    {
        *nr = *nr+n/50;
        n = n%50;
    }
    if(n/10 > 0)
    {
        *nr = *nr + n/10;
        n = n%10;
    }
    if(n/5 > 0)
    {
        *nr = *nr+n/5;
        n = n%5;
    }
    if(n>0)
    {
        *nr = *nr+n;
    }
}

int main()
{
    int n,nr=0;
    scanf("%d",&n);
    nrOfBacknotes(n,&nr);
    printf("%d",nr);
    return 0;
}
