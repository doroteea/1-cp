#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt "\nPress a key!"

int main() {

    char string1[]="STRING1 OF CHARACTERS";
    char *string2="STRING2 OF CHARACTERS";
    char string3[100];int i;
    printf("string1: %s", string1);
    strcpy(string3, string1);
    printf("string3(=string1): %s", string3);
    strcat(string3, string2);
    printf("\nstring3(=string3+string2): %s\n", string1);
    strncat(string3, string2, 5);
    printf("Contents of string 3 in hex:");
    for (i=0; i <= strlen(string3)+1; ++i)
        printf("%x", string3[i]);
    printf("\nstring3(as text): %s\n", string3);
    puts(prompt);
    getchar();
    return 0;

    return 0;
}
