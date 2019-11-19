#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt "Press a key"

int main()
{

    char s1[]="String1";
    char *s2="String2";
    int n1, n2;

    n1 = strlen (s1);
    n2 = strlen (s2);

    printf("n1=%d n2=%d\n", n1, n2);



    char *s=(char*)malloc(sizeof(char)*100);
    gets(s);///ia in considerare spatiile
    scanf("%s", s);///nu ia in considerare spatiile


    strcat(s1, s2);
    printf("%s\n", s1);

    printf("%d\n", strcmp(s1, s2));


    return 0;
}
