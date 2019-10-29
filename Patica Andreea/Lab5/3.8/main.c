#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateArabian (char n)
{
    if (n=='I')
    {
        return 1;
    }
    if (n=='X')
    {
        return 10;
    }
    if (n=='L')
    {
        return 50;
    }
    if (n=='C')
    {
        return 100;
    }
    if (n=='D')
    {
        return 500;
    }
    if (n=='M')
    {
        return 1000;
    }
    else
    {
        return 0;
    }
}

int findArabian (char number[])
{
    int length=strlen(number);
    int i=0, x, y;
    int Arabian=0;

    while (i<length)
    {
        x = calculateArabian(number[i]);
        if (i+1<length)
        {
            y = calculateArabian(number[i+1]);
        }
        else
        {
            y=0;
        }

        if (x<y)
        {
            Arabian += y-x;
            i+=2;
        }
        else
        {
            Arabian += x;
            i++;
        }

    }

    return Arabian;
}

int main()
{
    char number[100];
    printf("Insert the number!\nnumber=");
    scanf("%s", number);
    printf("%d", findArabian(number));
           return 0;
}
