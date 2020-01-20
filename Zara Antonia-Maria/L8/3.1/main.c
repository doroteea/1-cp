/* Program L9Ex1.c */
/* The usage of the function  strlen */

/**
#include <stdio.h>
#include <string.h>
#define prompt "Press a key!"
int main(void)
{
    char string1[]="STRING OF CHARACTERS";
    char  * string2="STRING OF CHARACTERS";
    int n1, n2, n3;
    n1=strlen(string1)
    ;n2=strlen(string2);
    n3=strlen("STRING OF CHARACTERS");
    /* The values of n1, n2 and n3 are the same, i.e. 20
    printf("\n n1=%d n2=%d n3=%d\n", n1, n2, n3);
    printf("%s\n", prompt);
    getchar();
    return 0;
}
*/

int main(void)
{
    char string1[]="STRING1 OF CHARACTERS";
    char *string2="STRING2 OF CHARACTERS";
    char string3[100];
    int i;
    printf("string1: %s", string1);
    strcpy(string3, string1);
    printf("string3(=string1): %s", string3);
    strcat(string3, string2);
    printf("\nstring3(=string3+string2): %s\n", string1);
    strncat(string3, string2, 5);
    printf("\n contents
            of string 3 in hex:");
    for (i=0; i <= strlen(string3)+1; ++i)
        printf("%x", string3[i]);
    printf("\nstring3(as text): %s\n", string3);

    getchar();
    return 0;
}
