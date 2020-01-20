#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,cif=0,pow=1,dec=0;
    printf("introduce number: ");
    scanf("%d",&n);
    while(n>0)
    {
        cif=n%10;
        n=n/10;
        dec=dec+cif*pow;
        pow=pow*16;

    }
    printf("%d",dec);
    return 0;
}
