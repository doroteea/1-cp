#include <stdio.h>
#include <string.h>
#include <stdlib.h>


const char removeFromString( char str[] , int t)
{
    int j;
    for(j=0; j<t; j++)
    {
                str[j]=str[j+1];

    }
}

int main() {
   char *string1 = (char*)malloc(sizeof(char)*50);
   char *string2 = (char*)malloc(sizeof(char)*50);
   char *string3 = (char*)malloc(sizeof(char)*50);
    int posi;

    printf("Hello, World!\n");
    printf("Enter your string: ");
    scanf("%s[^\n]",string1);
    printf ("Enter the string you want to enter ");
    scanf ("%s[^\n]",string2);
    scanf ("%d",&posi);
    strncpy(string3, string1, posi-1);
    removeFromString(string1,strlen(string1));
    string3[posi] = '\0';
    strcat(string3,string2);
    strcat(string3,string1);
    printf ("%s \n",string3);

    return 0;
}