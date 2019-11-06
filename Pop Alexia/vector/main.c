#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[100],n,sum=0,a=0,i;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&v[i]);
        if(v[i]>a)
        {
            a=v[i];
        }
    }
    printf("%d\n",a);
    while(a>0)
    {
        sum=sum+a%10;
        a/=10;

    }
    printf("the sum of the digits of the biggest number in the array is %d",sum);
    return 0;
}
