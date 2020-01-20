#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    printf("Please insert the year: \nyear=");;
    scanf("%d",&year);
    while(year<1600 || year>4900)
    {
        printf("The year is not correct. Please insert another value:\nyear=");
        scanf("%d",&year);
    }
    if(year%4==0)
    {
        printf("The year %d is bissextile.",year);
    }
    else
    {
        printf("The year %d is not bissextile.",year);
    }
    return 0;
}
