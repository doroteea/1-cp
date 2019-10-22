#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,invn=0,aux,cif;
    printf("introduce the number:");
    scanf("%d",&n);
    aux=n;

    do
    {
        cif=n%10;
        n=n/10;
        invn=invn*10+cif;

    }
    while(n>0);

    if(aux==invn)
        printf("the number is palindrome");
    else
        printf("the number is not palindrome");
    return 0;
}
