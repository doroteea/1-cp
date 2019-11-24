#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char getGender()
{
    char gender=getch();
    return gender;
}

char getValidGender()
{
    printf("Please input gender (m or f):");
    char gender=getGender();
    while(gender!='m' && gender!='f')
    {
        printf("\nInvalid input, please try again: ");
        gender=getGender();
    }
    return gender;
}

int getInteger()
{
    unsigned int value;
    scanf("%d", &value);
    return value;
}


int readPostivieInteger(char * type)
{
    printf("\nPlease input the %s:", type);
    unsigned int value = getInteger();
    while(value<=0)
    {
        printf("\nInvalid input, please input a positive value: ");
        value=getInteger();
    }
    return value;
}

float idealWeight(char gender, int age, int height)
{
    float weight;
    if(gender=='m')
    {
        weight=50 + 0.75*(height-150) + (age-20)/4 +3;
    }
    else
    {
        weight=50 + 0.75*(height-150) + (age-20)/4 -7;
    }

    return weight;
}

