/*Read from the standard inputthe hexadecimal digits of aninteger hexadecimal number.
Find and display the equivalent decimal number.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    char hex[50];
    double dec = 0;
    int i;
    gets(hex);
    puts(hex);
    i = strlen(hex) - 1;

    while(i >= 0)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
            dec = (hex[i]-'0')*pow(16,i);
        else
        {
            if(hex[i] == 'A')
            {
                dec = 10*pow(16,i);
            }
            else if(hex[i] == 'B')
            {
                dec = 11*pow(16,i);
            }
            else if(hex[i] == 'C')
            {
                dec = 12*pow(16,i);
            }
            else if(hex[i] == 'D')
            {
                dec = 13*pow(16,i);
            }
            else if(hex[i] == 'E')
            {
                dec = 14*pow(16,i);
            }
            else if(hex[i] == 'F')
            {
                dec = 15*pow(16,i);
            }
        }
        i--;
    }
    printf("%lf", dec);
    return 0;
}
