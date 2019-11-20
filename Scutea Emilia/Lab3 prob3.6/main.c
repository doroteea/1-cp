#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,aux=0,m=0;
    printf("introduce n:");
    scanf("%d",&n);
    aux=n;
    while (aux!=0)
    {
        m=m*10+aux%10;
        aux=aux/10;
    }
    if(n==m)
    {
        printf("The number %d is palindrome",n);
    }
    else
    {
        printf("The number %d is not palindrome",n);
    }

    return 0;
}
