#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,verify;
    verify=1;
    scanf("%d",&year);
    if(year%4!=0)
    {
        verify=0;
    }
    else if(year%100!=0)
    {
        verify=1;
    }
    else if(year%400==0)
    {
        verify=1;
    }
    else
        verify=0;
    if(verify==0)
    {
        printf("The year is not leap");
    }
    else
        printf("The year is leap");
    return 0;
}
