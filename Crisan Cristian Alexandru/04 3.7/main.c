#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*3.7.  Read from the standard input the hexadecimal digits of
 an integer hexadecimal number.
 Find and display the equivalent decimal number*/
int HexadecimalToDecimal (int nr)
{
    int NewDecimalNumber=0;
    int power=0;
    while(nr>0&&nr%16!='x')
    {
        NewDecimalNumber+=(nr%16*pow(16,power));
           power++;
           nr/=16;
    }
    return NewDecimalNumber;
}
int main()
{
  int nr;
  scanf("%x",&nr);
   printf("The number %x in decimal is: %d",nr,HexadecimalToDecimal(nr));


    return 0;
}
