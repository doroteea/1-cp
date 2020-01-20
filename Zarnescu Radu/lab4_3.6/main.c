#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    long n,aux,x=0;
    scanf("%d",&n);
    aux=n;
    while(aux!=0)
    {
        x=x*10+aux%10;
        aux=aux/10;
    }
     if(x==n)
     {
         printf("The number is a palindrome");
     }
     else
     {
         printf("The number is not a palindrome");
     }

    return 0;
}
