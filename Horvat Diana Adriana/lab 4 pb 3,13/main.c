#include <stdio.h>
#include <stdlib.h>
int i,left,right,mid,v[100],k,n,x;
int main()
{
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&v[i]);
    }
    scanf("%d",&x);
    left=0;
    right=n;
    mid=n/2;
    k=0;
    while(left<=right)
    {
        if(v[mid]==x)
        {
            printf("%d,%d",mid,x);
            break;
        }
        if(v[mid]<x)
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        if(v[mid]>x)
        {
            right=mid-1;
            mid=(left+right)/2;
        }
    }

    return 0;
}
