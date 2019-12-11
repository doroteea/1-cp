#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char *s)
{
    int length = strlen(s);
    char *result = (char*)malloc(length+1);
    char *pointer = s;

    int d=0;
    for ( char ch = 'a' ; ch <= 'z' ; ch++ )
    {
        for ( int c = 0 ; c < length ; c++ )
        {
            if ( *pointer == ch )
            {
                *(result+d) = *pointer;
                d++;
            }
            pointer++;
        }
        pointer = s;
    }
    *(result+d) = '\0';

    strcpy(s, result);
    free(result);
}

int main()
{
    char string[100];

    printf("Enter some text\n");
    gets(string);

    sortString(string);
    printf("%s\n", string);

    return 0;
}

