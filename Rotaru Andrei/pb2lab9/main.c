#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *extractSubstring(char *string1,int position,int length)
{
    char *string2=(char*)malloc(sizeof(char)*50);
    int j=0;
    for(int i=position-1; i<position+length-1; i++)
    {
        string2[j]=string1[i];
        j++;
    }
    string2[j]='\0';
    return string2;
}

int main()
{
    char *string1=(char*)malloc(sizeof(char)*50);
    char *string2=(char*)malloc(sizeof(char)*50);
    int position,length;
    printf("Enter the starting position and the length of the substring\n");
    scanf("%d %d",&position,&length);
    printf("Enter the string:\n");
    getchar();
    gets (string1);
    string2=extractSubstring(string1,position,length);
    printf("The substring is:\n");
    puts (string2);
    return 0;
}

