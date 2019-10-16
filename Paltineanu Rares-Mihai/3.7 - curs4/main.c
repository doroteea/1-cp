/**Read from the standard inputthe hexadecimal digits of aninteger hexadecimal number.
Find and display the equivalent decimal number.
*/
///A291 - 4
/// I = 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int verif(char hex[50])
{
    int i = strlen(hex) - 1;
    for(int j = 0; j <= i; j++)
    {
        if(hex[j]>'F')
        {
            return 0;
        }

    }
    return 1;
}

int main()
{
    char hex[50];
    double dec = 0;
    int i;
    gets(hex);
    while(verif(hex) == 0)
    {
        printf("Invalid nr, please read another nr ");
        gets(hex);
    }
    i = strlen(hex) - 1;

    while(i >= 0)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            dec = dec + (hex[i]-'0')*pow(16,strlen(hex) - i - 1);
        }
        else
        {
            if(hex[i] == 'A')
            {
                dec = dec + 10*pow(16,strlen(hex) - i - 1);
            }
            else if(hex[i] == 'B')
            {
                dec = dec + 11*pow(16,strlen(hex) - i - 1);
            }
            else if(hex[i] == 'C')
            {
                dec = dec + 12*pow(16,strlen(hex) - i - 1);
            }
            else if(hex[i] == 'D')
            {
                dec = dec + 13*pow(16,strlen(hex) - i - 1);
            }
            else if(hex[i] == 'E')
            {
                dec = dec + 14*pow(16,strlen(hex) - i - 1);
            }
            else if(hex[i] == 'F')
            {
                dec = dec + 15*pow(16,strlen(hex) - i - 1);
            }
        }
        i--;
    }
    printf("%lf", dec);
    return 0;
}
