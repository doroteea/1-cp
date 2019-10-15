#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int x,ok=0;
    printf("Input the year: ");
    scanf("%u",&x);
    if(x%400==0)ok=1;
        else
            if(x%4==0 && x%100!=0)ok=1;
    if(ok==1)printf("The year %u is a bissextile year.",x);
        else printf("The year %d is not a bissextile year.",x);

    return 0;
}
