#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int n,i,j,prime;
    scanf("%d",&n);
    printf("1 2 3 ");
    for(i=5; i<=n; i=i+2)
    {
        prime=1;
        for(j=3; j<=i/2; j=j+2)
        {
            if(i%j==0)
                prime=0;
        }
        if(prime==1)
        {
            printf("%d ",i);
        }
    }
    return 0;
}
