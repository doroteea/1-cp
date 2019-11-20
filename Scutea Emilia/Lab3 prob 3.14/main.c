
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],n,i;
    int x,ct,pos,maxim=0,maxpos;
    printf("Introduce n:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nIntroduce the element:");
        scanf("%d",&a[i]);
    }
    x=a[0];
    ct=1;
    pos=0;
    for(i=1; i<n; i++)
    {
        if(x<=a[i])
        {
            ct++;
        }
        else
        {
            if(ct>maxim)
            {
                maxim=ct;
                maxpos=pos;
            }
            ct=1;
            pos=i;
        }
        x=a[i];
    }
    if(ct>maxim)
            {
                maxim=ct;
                maxpos=pos;
            }
    printf("The maximum length subsequence in ascending order is: ");
    for(i=maxpos; i<maxpos+maxim; i++)
    {
        printf("%d   ",a[i]);
    }

    return 0;
}
