#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, d, integerSquare, foundPerfectSquare, foundPrimeNumber, flag;
    float floatSquare;

    printf("n=");
    scanf("%d", &n);

    foundPerfectSquare=0;
    for (i=n;i>=1 && foundPerfectSquare==0;i--)
    {
        floatSquare=sqrt((double)i);
        integerSquare=floatSquare;
        if (integerSquare==floatSquare)
        {
            printf("The greatest perfect square that is less than or equal to n is: %d\n", i);
            foundPerfectSquare=1;
        }
    }

    foundPrimeNumber=0;
    for (i=n;i<=2147483647 && foundPrimeNumber==0;i++)
    {
        flag=0;
        for (d=2;d<=i/2;d++)
        {
            if (i%d==0)
            {
                flag = 1;
                break;
            }
        }
        if (flag==0)
        {
            printf("The least prime number that is greater than or equal to n is: %d\n", i);
            foundPrimeNumber=1;
        }
    }

    return 0;
}