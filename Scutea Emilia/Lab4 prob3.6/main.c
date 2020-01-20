#include <stdio.h>
#include <stdlib.h>

int computePalindromeNumber(int n)
{
    int aux=0;
    while(n!=0)
    {
        aux=aux*10+n%10;
        n=n/10;
    }
    return aux;
}

int main()
{
    int n;
    printf("Please input the number n:\nn=");
    scanf("%d",&n);
    if(computePalindromeNumber(n)==n)
    {
        printf("The number %d is palindrome.",n);
    }
    else
    {
        printf("The number %d is not palindrome.",n);
    }
}
