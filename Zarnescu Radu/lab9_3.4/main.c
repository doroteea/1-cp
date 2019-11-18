#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void extraction(char *string1,int pos,int length)
{
    int i,initialLength,j;
    initialLength=strlen(string1);
    for(i=length+pos,j=pos; j<=length; j++,i++)
    {
        string1[j]=string1[i];
    }
    string1[initialLength-length]='\0';
}
int main()
{
    printf("Hello world!\n");
    char *string1=(char*)malloc(sizeof(char)*20);
    int pos,length;
    scanf("%d %d",&pos, &length);
    getchar();
    gets(string1);
    extraction(string1,pos,length);
    puts(string1);
    return 0;
}
