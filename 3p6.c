#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverse (char * str, int length)
{
    int i = 0, j = length - 1;
    char x;
    while (i < j)
    {
        x = str[i];
        str[i] = str[j];
        str[j] = x;
        i++;
        j--;
    }
}

int intToStr (int x, char * str, int minimumDigits)
{
    int noOfDigits = 0;
    while (x != 0)
    {
        str[noOfDigits] = x % 10 + '0';
        noOfDigits++;
        x /= 10;
    }
    reverse (str, noOfDigits);
    while (noOfDigits < minimumDigits)
    {
        str[noOfDigits] = '0';
        noOfDigits++;
    }
    str[noOfDigits] = '\0';
    return noOfDigits;
}

void floatToStr (float x, char * res, int afterPoint)
{
    int integerPart = (int)x;
    float floatPart = x - (float)integerPart;
    int i = intToStr (integerPart, res, 0);
    if (afterPoint != 0)
    {
        res[i] = '.';
        floatPart = floatPart * pow (10, afterPoint);
        intToStr ((int)floatPart, res + i + 1, afterPoint);
    }
}

int main ()
{
    char *res = (char*) malloc (sizeof (char) * 25);
    printf ("Please insert a positive real number:\nx = ");
    float x;
    scanf ("%f", &x);
    floatToStr (x, res, 5);
    printf ("%s", res);
    return 0;
}
