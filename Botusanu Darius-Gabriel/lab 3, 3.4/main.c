#include <stdio.h>
#include <stdlib.h>
/*Alex, it's a miracle! This program actually works!!!*/

int main()
{
    long y;
    printf("Please input a year in the range of [1600,4900]: \n");
    scanf("%ld", &y);
    if(y%4==0)
    {
        printf("It is a leap year");
    }
    if(y%4!=0)
    {
        printf("It is not a leap year");
    }
    return 0;
}
