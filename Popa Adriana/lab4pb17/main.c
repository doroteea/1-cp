#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n,b,cif,nr=0,v[100],ct=1,i;
    printf("introduce n:");
    scanf("%u",&n);
    printf("introduce base:");
    scanf("%u",&b);
    while(n>0)
    {
        cif=n%b;
        v[ct++]=cif;
        n=n/b;
    }
     printf("\nthe number in base %u is ",b);
     for(i=ct;i>=1;i--)
        printf("%u",v[i]);
    return 0;
}
