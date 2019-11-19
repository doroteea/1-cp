#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMax 300

int main()
{
    int n;
    printf("Insert the number of strings!\n");
    scanf("%d", &n);

    char *s=(char*)malloc(sizeof(char)*NMax);
    int maxLength=0;
    char *maxLengthString=(char*)malloc(sizeof(char)*NMax);

    printf("Insert the strings!\n");
    for (int i=0; i<n; i++)
    {
        scanf("%s", s);
        int len=strlen(s);
        if (len>maxLength)
        {
            maxLength=len;
            strcpy(maxLengthString, s);
        }
        else if (len==maxLength && strcmp(maxLengthString, s)<0)
        {
            strcpy(maxLengthString, s);
        }

    }

    printf("The string is:\n%s", maxLengthString);
    return 0;
}
