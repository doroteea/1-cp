#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    scanf("%d",&year);
    if((year%400)==0)
    {
        printf("Year %d is not a leap year",year);
    }
    else if((year%4)==0)
            {
                printf("Year %d is a leap year",year);
            }
            else printf("Year %d is not a leap year",year);
    return 0;
}
