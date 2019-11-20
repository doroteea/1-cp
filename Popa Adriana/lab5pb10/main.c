#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a[7]= {500,200,100,50,10,5,1},ct=0;
    printf("introduce the amount of money:");
    scanf("%d",&n);
    for(i=0; i<7; i++)
    {
        while(n>=a[i])
        {
            ct++;
            n=n-a[i];
        }
    }
    printf("%d",ct);
    return 0;
}
