#include <stdio.h>
#include <stdlib.h>
int n,copy,symmetric=0;
int main()
{
    scanf("%d",&n);
    copy=n;
    while(n)
    {
        symmetric=symmetric*10+n%10;
        n/=10;
    }
    if(symmetric==copy)
    {
        printf("n is a palindrome");
    }
    else
    {
        printf("n is not a palindrome");
    }
    return 0;
}
