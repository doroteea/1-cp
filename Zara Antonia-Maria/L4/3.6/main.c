///palindrome
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr,copy,newNr=0,lastDigit;
    scanf("%d",&nr);
    copy=nr;
    do
    {
        lastDigit=copy%10;
        newNr=newNr*10+lastDigit;
        copy=copy/10;
    }
    while(copy!=0);
    if(nr==newNr)printf("The number is a palindrome.");
        else printf("The number is not a palindrome.");
    return 0;
}
