#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,l,i,v[100],lmax,poz,pozmax;
    printf("introduce n:");
    scanf("%d",&n);
    printf("introduce numbers:");
    scanf("%d",&v[0]);
    l=1;
    lmax=1;
    poz=0;
    pozmax=0;
    for(i=1; i<n; i++)
    {
        scanf("%d",&v[i]);
        if(v[i]>v[i-1])
             l++;
        else
        {
            l=1;
            poz=i;
        }
        if(lmax<l)
        {
            lmax=l;
            pozmax=poz;
        }
    }
    for(i=pozmax; i<pozmax+lmax; i++)
        printf("%d , ",v[i]);
    return 0;
}
