#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char *s=(char*)malloc(sizeof(char)*20);
    gets(s);
    int i;
    for(i=0;i<strlen(s);i++)
    {
        s[i]=toupper(s[i]);
    }
    puts(s);
    return 0;
}
