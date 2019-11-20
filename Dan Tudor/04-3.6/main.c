#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,cop,inv=0;
    scanf("%d",&n);
    cop = n;
    while(n>0)
    {
        inv = inv*10+n%10;
        n=n/10;
    }
    if(inv == cop)
        printf("DA");
    else
        printf("NU");
    return 0;
}
