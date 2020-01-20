#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,sum=0,x,m[20],ct=0;
    printf("Input number of terms:");
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(x%2!=0)
        {
            sum+=x;
            m[ct]=x;
            ct++;
        }
    }
    printf("The odd numbers are:");
    for(i=0; i<ct; i++)
    {
        printf("%d ",m[i]);
    }
    printf("\nAnd their sum is %d ",sum);
    return 0;
}
