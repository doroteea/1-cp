#include <stdio.h>
#include <string.h>


const char removeFromString( char str[] , int t)
{
    int i,j;
    for(j=0; j<t; j++)
    {
                str[j]=str[j+1];

    }
}

int main() {
    char string1[50];
    char string2[50];
    char string3[50];
    int posi;

    printf("Hello, World!\n");
    printf("Enter your string: ");
    scanf("%s[^\n]",&string1);
    printf ("Enter the string you want to enter ");
    scanf ("%s[^\n]",&string2);
    scanf ("%d",&posi);
    strncpy(string3, string1, posi-1);
    removeFromString(string1,strlen(string1));
    string3[posi] = '\0';
    strcat(string3,string2);
    strcat(string3,string1);
    printf ("%s \n",string3);

    return 0;
}