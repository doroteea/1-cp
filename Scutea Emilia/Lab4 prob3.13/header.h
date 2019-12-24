#include <stdio.h>
#include <stdlib.h>
void readSequence(int *a,int n)
{

    for(int i=0; i<n; i++)
    {
        printf("Please insert a[%d]:",i);
        scanf("%d",&a[i]);

    }
}

void verifyExistence(int x,int *a,int n)
{

    int left=0,right=n-1,found=0;
    while(left<right && found==0)
    {
        int mid=(left+right)/2;
        if(x==a[mid])
        {
            found=1;
            printf("The number %d exists in the sequence on position %d",x,mid);
        }
        else
        {
            if(x<a[mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
    }
    if(found==0)
    {
        printf("The number %d does not exist in the sequence.",x);
    }
}
