#include <stdio.h>
#include <stdlib.h>

int main()
{
    int birthYear, currentYear;
    printf("Birth year=");
    scanf("%d", &birthYear);
    printf("Current year=");
    scanf("%d", &currentYear);

    printf("In binary number system, the birth year is: ");

    short print1=0;
    for (int i=31; i>=0; i--)
    {
        if ((birthYear>>i)&1)
        {
            print1=1;
            printf("1");
        }
        else if (print1)
        {
            printf("0");
        }
    }

    printf("\nIn binary number system, the current year is: ");

    print1=0;
    for (int i=31; i>=0; i--)
    {
        if ((currentYear>>i)&1)
        {
            print1=1;
            printf("1");
        }
        else if (print1)
        {
            printf("0");
        }
    }
    return 0;
}
