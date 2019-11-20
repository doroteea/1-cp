#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void initNULL (char *s, int length)
{
    for (int i=0; i<length; i++)
    {
        s[i]=NULL;
    }
}

void task2 ()
{
    printf("TASK2\n");
    int size;
    printf("Insert the length of the string!\n");
    scanf("%d", &size);

    char *sourceString=(char*)malloc(sizeof(char)*size);
    printf("Insert string!\n");
    scanf("%s", sourceString);


    int pos, length;
    printf("Insert position and length!\n");
    scanf("%d%d", &pos, &length);

    char *destString=(char*)malloc(sizeof(char)*length);
    strncpy(destString, sourceString+pos-1, length);

    printf("The new string is:\n%s\n", destString);

    printf("\n\n");
}

void task3 ()
{
    printf("TASK3\n");

    int size;
    printf("Insert the length of the string!\n");
    scanf("%d", &size);

    char *sourceString=(char*)malloc(sizeof(char)*size);
    printf("Insert string!\n");
    scanf("%s", sourceString);

    int length=6;
    char *destString=(char*)malloc(sizeof(char)*length);
    printf("Insert destination string!\n");
    scanf("%s", destString);

    int pos;
    printf("Insert the position for inserting the string!\n");
    scanf("%d", &pos);

    char *aux=(char*)malloc(sizeof(char)*length);
    initNULL(aux, length);

    strcpy(aux, destString+pos-1);

    char *aux2=(char*)malloc(sizeof(char)*length);
    initNULL(aux2, length);

    strncpy(aux2, destString, pos-1);
    strcpy(destString, aux2);
    strcat(destString, sourceString);
    strcat(destString, aux);

    printf("The new string is:\n%s\n", destString);
    printf("\n\n");
}

void task4 ()
{
    printf("TASK4\n");

    int size;
    printf("Insert the length of the string!\n");
    scanf("%d", &size);

    char *sourceString=(char*)malloc(sizeof(char)*size);
    printf("Insert string!\n");
    scanf("%s", sourceString);

    char *destString=(char*)malloc(sizeof(char)*size);
    initNULL(destString, size);
    int pos, length;
    printf("Insert the position and the length to delete the string!\n");
    scanf("%d%d", &pos, &length);
    strncpy(destString, sourceString, pos-1);
    destString[pos-1]=NULL;

    char *aux=(char*)malloc(sizeof(char)*size);
    initNULL(aux, size);
    strcpy(aux, sourceString+pos);

    strcat(destString, aux+length-1);

    printf("The new string is:\n%s\n", destString);
    printf("\n\n");

}

void task5 ()
{
    printf("TASK5\n");

    int size;
    printf("Insert the length of the string!\n");
    scanf("%d", &size);

    char *sourceString=(char*)malloc(sizeof(char)*size);
    printf("Insert string!\n");
    scanf("%s", sourceString);

    int length;
    printf("Insert the length of the given string!\n");
    scanf("%d", &length);
    char *givenString=(char*)malloc(sizeof(char)*length);
    printf("Insert the second string!\n");
    scanf("%s", givenString);


    bool substringFound=false;
    for (int i=0; i<size; i++)
    {
        if (sourceString[i]==givenString[0])
        {
            bool isSubstring=true;
            for (int j=0; j<length; j++)
            {
                if (givenString[j]!=sourceString[j+i])
                {
                    isSubstring=false;
                    break;
                }
            }
            if (isSubstring)
            {
                printf("The position of the given substring is: %d", i+1);
                substringFound=true;
                break;
            }
        }
    }
    if (!substringFound)
    {
        printf("Substring not found!\n");
    }
    printf("\n\n");
}

double convertStringIntoNumber (char *sourceString, int size)
{
    double p=1.0;
    double number=0.0;
    bool dot=false;
    for (int i=0; i<size; i++)
    {
        if (sourceString[i]=='.')
        {
            dot=true;
            p/=10;
        }
        else if (dot==false)
        {
            number=number*10+(sourceString[i]-'0');
        }
        else
        {
            number+=(sourceString[i]-'0')*p;
            p/=10;
        }
    }

    return number;
}

char* convertNumberIntoString (double number)
{
    char *stringNumber=(char*)malloc(sizeof(char)*30);
    initNULL(stringNumber, 30);

    int intNumber=(int)number;
    int power=1;
    while(intNumber/power!=0)
    {
        power*=10;
    }

    number-=intNumber;
    power/=10;

    int i=0;
    while (intNumber)
    {
        stringNumber[i]=intNumber/power+48;
        i++;
        intNumber%=power;
        power/=10;
    }

    if (number!=0.0)
    {
        stringNumber[i]='.';
        i++;
        number*=10;
        while ((int)number!=0)
        {
            printf("%lf\n",number);

            stringNumber[i]=(int)number%10+'0';

            i++;
            number-=(int)number;
            number*=10;
        }
    }
    return stringNumber;
}

void task6 ()
{
    printf("TASK6\n");

    int size;
    printf("Insert the length of the string!\n");
    scanf("%d", &size);

    char *sourceString=(char*)malloc(sizeof(char)*size);
    printf("Insert string!\n");
    scanf("%s", sourceString);

    double number=convertStringIntoNumber(sourceString, size);
    printf("The number is: %lf\n", number);

    printf("Insert the number you wish to convert into char string!\n");
    double number2;
    scanf("%lf", &number2);
    printf("The string is:\n%s", convertNumberIntoString(number2));
    printf("\n\n");
}

int main()
{
    task2();
    task3();
    task4();
    task5();
    task6();
    return 0;
}
