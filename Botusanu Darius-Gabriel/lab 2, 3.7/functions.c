#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

char * getString()
{
    char * string=(char*)malloc(sizeof(char)*SIZE);
    fgets(string, 20, stdin);
    return string;
}

char * checkUppercase(char * string)
{
    int i=0;
    while(string[i]<='A' && string[i]>='Z')
    {
        printf("\nInvalid input, please enter only lines in UPPERCASE characters:");
        string=getString();
    }
    while(string[i]>='A' && string[i]<='Z' && i<=(strlen(string)-1))
    {
        i++;
    }
    return string;
}

char * turnLowercase(char * string)
{
    int i;
    for(i=0;i<strlen(string)-1;i++)
    {
        string[i]+=32;
    }
    return string;
}
