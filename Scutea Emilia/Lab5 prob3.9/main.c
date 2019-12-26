#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convertToRoman(int number)
{
    char * num=(char*)malloc(sizeof(char)*10);
    int i=0;
    while(number>=1000)
    {
        number=number-1000;
        strcpy(num+i,"M");
        i++;
    }
    while(number>=500)
    {
        number=number-500;
        strcpy(num+i,"D");
        i++;
    }
    while(number>=100)
    {
        number=number-100;
        strcpy(num+i,"C");
        i++;
    }
    while(number>=50)
    {
        number=number-50;
        strcpy(num+i,"L");
        i++;
    }
    while(number>=10)
    {
        number=number-10;
        strcpy(num+i,"X");
        i++;
    }
    while(number>=5)
    {
        number=number-5;
        strcpy(num+i,"V");
        i++;
    }
    while(number>=1)
    {
        number=number-1;
        strcpy(num+i,"I");
        i++;
    }
    strcpy(num+i,"\0");

    return num;
}
int main()
{
    int number;
    printf("Please insert a number:\nnumber=");
    scanf("%d",&number);
    char * num=convertToRoman(number);
    printf("The number %d in Arabian base is %s in Roman base.",number,num);
}
