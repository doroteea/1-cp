#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x=n, m=0;
    while (x)
    {
        m=m*10+x%10;
        x/=10;
    }

    if (m==n)
    {
        printf("The number is palindrome.");
    }
    else
    {
        printf("The number is not palindrome.");
    }

    return 0;
}
