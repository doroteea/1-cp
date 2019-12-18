#include <stdio.h>
#include <stdlib.h>

int number;
int calculatePowerAndDivisor (int number, int *divisor)
{
    int power=0;
    *divisor=1;
    while (number/(*divisor)>9)
    {
        power++;
        *divisor=*divisor*10;
    }
    return  power;
}

void printRoman(int number)
{
    int divisor;
    char *table[4][10]=
            {
                    {
                        "","I","II","III","IV","V","VI","VII","VIII","IX"
                    },
                    {
                        "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"
                    },
                    {
                        "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"
                    },
                    {
                        "","M","MM","MMM"
                    }
            };
    int power=calculatePowerAndDivisor(number,&divisor);
    while(power>=0)
    {
        printf("%s",table[power][number/divisor]);
        number=number%divisor;
        divisor=divisor/10;
        --power;
    }
}

int main()
{
    printf("Give decimal number: ");
    scanf("%d", &number);
    printf("Roman number is: ");
    printRoman(number);
    return 0;
}