#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main()
{
    printf("Please enter a line in UPPERCASE characters: ");
    char * string=getString();
    checkUppercase(string);
    printf("\nThis is the string in lowercase characters: %s", turnLowercase(string));
    return 0;
}
