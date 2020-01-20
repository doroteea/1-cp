##include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,k=0;
    char s[100];
    scanf("%d",&n);
    while (n>0)
    {
        inv=inv*10+n%10;
        n=n/10;
        k++;
    }
    itoa(n,s,k);
    printf("%s\n",s);
    return 0
}
