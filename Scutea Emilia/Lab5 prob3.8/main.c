#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void convertNumber(char roman[],char *number)
{
    int num=0;
    for(int i=0; i<strlen(number); i++)
    {
        if(number[i]=='M')
        {
            num=num+1000;
        }
        else
        {
            if(number[i]=='D')
            {
                num=num+500;
            }
            else
            {
                if(number[i]=='C')
                {
                    num=num+100;
                }
                else
                {
                    if(number[i]=='L')
                    {
                        num=num+50;
                    }
                    else
                    {
                        if(number[i]=='X')
                        {
                            num=num+10;
                        }
                        else
                        {
                            if(number[i]=='V')
                            {
                                num=num+5;
                            }
                            else
                            {
                                if(number[i]=='I')
                                {
                                    num=num+1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("The number %s in Roman base is %d in Arabian base.",number,num);
}

int main()
{
    char roman[8]= {'I','V','X','L','C','D','M'};
    char * number=(char*)malloc(sizeof(char)*10);
    printf("Enter number: ");
    scanf("%s", number);
    getchar();
    printf("Your number is %s.\n", number);
    convertNumber(roman,number);
}
