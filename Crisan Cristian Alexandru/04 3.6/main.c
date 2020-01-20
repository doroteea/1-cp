#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*3.6.  Read from the standard input a natural number, n .
 Check if this number is palindrome*/
int ReversedDigits(int nr)
{
    int NewNumber=0;
    while(nr>0)
    {NewNumber=NewNumber*10+nr%10;
    nr=nr/10;
    }
    return NewNumber;
}
bool CheckPropertyOfPalindrome(int nr)
{
    if(nr==ReversedDigits(nr))
    {
        return true;
    }
    else {return false;}
}
int main()
{
int nr;
 scanf("%d",&nr);
if(CheckPropertyOfPalindrome(nr))
{
    printf("The given number is a palindrome.");

}
else printf("The given number isn't a palindrome");
    return 0;
}
