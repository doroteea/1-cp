#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned n,aux,reverse=0,p;
    printf("Enter number:\n");
    scanf("%d",&n);
    aux=n;
    while(aux!=0)
    {
        p=aux%10;
        reverse=reverse*10+p;
        aux=aux/10;

    }
    if(n==reverse)
    {
        printf("The number is palindrome\n");
    }
    else
    {
        printf("The number isn't palindrome \n");
    }
    return 0;
}
