#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numar,invers=0,copienr;
    scanf("%d",&numar);
    copienr=numar;
    while(copienr)
    {
        invers=invers*10+copienr%10;
        copienr/=10;
    }
    if(numar==invers)
    {
        printf("Numarul e palindrom");
    }
    else
    {
        printf("numarul nu este palindrom");
    }
    return 0;
}
