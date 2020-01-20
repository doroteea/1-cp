#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int verif(char hex[200])
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

///firstly i write the function like this: void convert(char hex[200], double &a)
///but the error is saying "expected ';', ',', or ')' before '&' token and idk what is meaning

int convert(char hex[200], double a)
{
    int b = strlen(hex);
    for(int i = 0; i < b; i++)
    {
        switch(hex[i])
        {
        case '1':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '2':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '3':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '4':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '5':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '6':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '7':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '8':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '9':
            a = a + (hex[i] - '0')*(pow(16,strlen(hex) - i - 1));
            break;

        case '0':
            break;

        case 'A':
            a = a + 10*pow(16,strlen(hex) - i - 1);
            break;

        case 'B':
            a = a + 11*pow(16,strlen(hex) - i - 1);
            break;

        case 'C':
            a = a + 12*pow(16,strlen(hex) - i - 1);
            break;

        case 'D':
            a = a + 13*pow(16,strlen(hex) - i - 1);
            break;

        case 'E':
            a = a + 14*pow(16,strlen(hex) - i - 1);
            break;

        case 'F':
            a = a + 15*pow(16,strlen(hex) - i - 1);
            break;
        }
    }
    return a;
}
int main()
{
    char hex[200];
    double decim = 0;
    gets(hex);
    int i = strlen(hex) - 1;

    while(verif(hex) == 0)
    {
        printf("Invalid nr, please read another nr ");
        gets(hex);
    }

    decim = convert(hex, decim);
    printf("The nr in decimal is %lf", decim);
    return 0;
}
