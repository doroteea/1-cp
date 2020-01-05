#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *verify(char* subString, char* String)
{
    return strstr(String,subString);
}

int main()
{
    return 0;
}
