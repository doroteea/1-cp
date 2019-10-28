#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int convert(char *romanNr)
{
    int decimalNr=0,i,size,nr;
    size=strlen(romanNr);
    for(i=0; i<size; i++)
    {
        if(romanNr[i]=='M')
        {
            decimalNr=decimalNr+1000;
        }
        if(romanNr[i]=='D')
        {
            decimalNr=decimalNr+500;
        }
        if(romanNr[i]=='C')
        {
            if(romanNr[i+1]=='D')
            {
                decimalNr=decimalNr+400;
                i++;
            }
            else
            {
                if(romanNr[i+1]=='M')
                {
                    decimalNr=decimalNr+900;
                    i++;
                }
                else
                {
                    decimalNr=decimalNr+100;
                }
            }
        }
        if(romanNr[i]=='L')
        {
            decimalNr=decimalNr+50;
        }
         if(romanNr[i]=='X')
        {
            if(romanNr[i+1]=='L')
            {
                decimalNr=decimalNr+40;
                i++;
            }
            else
            {
                if(romanNr[i+1]=='C')
                {
                    decimalNr=decimalNr+90;
                    i++;
                }
                else
                {
                    decimalNr=decimalNr+10;
                }
            }
        }
         if(romanNr[i]=='V')
        {
            decimalNr=decimalNr+5;
        }
         if(romanNr[i]=='I')
        {
            if(romanNr[i+1]=='V')
            {
                decimalNr=decimalNr+4;
                i++;
            }
            else
            {
                if(romanNr[i+1]=='X')
                {
                    decimalNr=decimalNr+9;
                    i++;
                }
                else
                {
                    decimalNr=decimalNr+1;
                }
            }
        }

    }
    return decimalNr;
}
int main()
{
    printf("Hello world!\n");
    char romanNr[20];
    int nr;
    scanf("%s",romanNr);
    nr= convert(romanNr);
    printf("%d",nr);
    return 0;
}
