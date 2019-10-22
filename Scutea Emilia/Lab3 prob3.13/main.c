#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[100],x;
    int n,i,lf,rg,mid,ok;
    printf("Introduce n:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("\nIntroduce the element:");
        scanf("%f",&a[i]);
        printf("%f",a[i]);
    }
    printf("\nIntroduce x:");
    scanf("%f",&x);
    lf=0;
    rg=n-1;
    ok=0;
    while(lf<=rg && ok==0)
    {
        mid=(lf+rg)/2;
        if(x==a[mid])
        {
            ok=1;
            printf("The number %f exists in the given sequence on position %d",x,mid);
            break;
        }
        else
        {
            if(x<a[mid])
            {
                rg=mid-1;
            }
            else
            {
                lf=mid+1;
            }
        }
    }
    if(ok==0)
    {
        printf("The number %f does not exist in the given sequence",x);
    }
    return 0;
}
