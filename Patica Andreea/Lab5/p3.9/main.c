#include <stdio.h>
#include <stdlib.h>

int calculatePowerAndDivisor (int number, int *divisor)
{
    int power=0;
    *divisor=1;
    while (number/ *divisor > 9)
    {
        ++power;
        *divisor *= 10;
    }
    return power;
}

void printRoman (int number)
{
    char *roman[4][10]=
    {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };

    int divisor;
    int power = calculatePowerAndDivisor(number, &divisor);

    while (power>=0)
    {
        printf("%s", roman[power][number/divisor]);
        if (divisor>1)
        {
            number %= divisor;
            divisor /=10;
            --power;
        }
        else
            break;
    }
}

int main()
{

    int number;
    printf("Insert the number!\nnumber=");
    scanf("%d", &number);
    printRoman(number);
    return 0;
}
