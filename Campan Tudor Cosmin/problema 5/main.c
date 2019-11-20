#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,k,inv=0;
    char s[100];
    scanf("%d",&n);
    while (n>0)
    {
        inv=inv*10+n%10;
        n=n/10;
        k++;
    }
    for(int i=0; i<k; i++)


    {

        s[i]=inv%10;
        inv=inv/10;
    }
    printf("%s",s);

    return 0;
}
