#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,ps,prime=0,d;
    printf("introduce n:");
    scanf("%d",&n);
    ps=sqrt(n);
    if(n>=1)
        printf("the greatest perfect square smaller than n is: %d",ps*ps);
    else
        printf("there do not exist the greatest perfect square smaller than n" );
    printf("\nthe least prime number greater than or equal to n is: ");
    if(n<=2)
        printf("2");
    else
        while(prime==0)
    {
        prime=1;
        for(d=3;d<=n/2;d++)
            if(n%d==0)
                prime=0;
        n++;
    }
    printf("%d",n-1);
    return 0;
}
