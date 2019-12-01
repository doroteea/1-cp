///3.7.Write a program to read n strings of characters and display both the longest string
///    and the biggest one as seen as an alphanumeric sequence.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char determineLongest(char string1, char string2)
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    if(length1>length2)
    {
        return string1;
    }
    else
    {
        return string2;
    }
}

char determineAlphanumericalFirst(char string1, char string2)
{
    if(strcmp(string1,string2)<0)
    {
        return string1;
    }
    else
    {
        return string2;
    }
}

int main()
{
    int nrStrings,i;
    scanf("%d",&nrStrings);

    char currentString[1001];
    char longestString[1001];
    char biggestAlphaString[1001];

    scanf("%s",&currentString);
    strcpy(longestString,currentString);
    strcpy(biggestAlphaString,currentString);

    for(i=1; i<nrStrings; i++)
    {
        scanf("%s",&currentString);
        printf("%d ",i);

        ///aici mi se blocheaza cand imi intra in functii
        strcpy(longestString,determineLongest(currentString,longestString));
        strcpy(biggestAlphaString,determineAlphanumericalFirst(currentString,biggestAlphaString));
    }

    printf("The longest string is %s\n",longestString);
    printf("The biggest alphanumerical string is %s",biggestAlphaString);

    return 0;
}
