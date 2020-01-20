#include <stdio.h>

int main()
{
    int n, inverseNumber, copy, lastDigit;
    printf("n= ");
    scanf("%d", &n);
    copy=n;
    inverseNumber=0;
    while (copy>0)
    {
        lastDigit=copy%10;
        inverseNumber=inverseNumber*10+lastDigit;
        copy=copy/10;
    }

    if (inverseNumber==n)
    {
        printf("n is a palindrome\n");
    }
    else
    {
        printf("n is not a palindrome\n");
    }

    return 0;
}