#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,palindrom,ncopy;
    scanf("%d",&number);
    palindrom = 0;
    ncopy=number;

    while(ncopy != 0)
    {
        palindrom = 10 * palindrom + ncopy%10;
        ncopy=ncopy/10;

    }
    if(number == palindrom)
    {
        printf("The input number is palindrome");
    }
    else{
        printf("The input number is not a palindrome");
    }
    return 0;
}
