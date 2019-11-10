#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,poz1,poz2,n;
    float mn=9999,mx=-9999,var;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%f",&var);
        if(var>mx)
        {
            mx=var;
            poz1=i;
        }
        if(var<mn)
        {
            mn=var;
            poz2=i;
        }
    }
    printf("%f,%d,%f,%d",mx,poz1,mn,poz2);

    return 0;
}
