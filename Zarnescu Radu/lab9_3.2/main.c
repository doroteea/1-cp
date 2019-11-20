#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* extract(char *string1,int pos,int length)
{
    char *string2 = (char*)malloc(sizeof (char)*20);
    int i,j=0;
    for(i=pos; i<pos+length; i++)
    {
        string2[j]=string1[i];
        j++;
    }
    string2[j]='\0';
    return string2;
}
int main()
{
    printf("Hello world!\n");
    int pos,length;
    scanf("%d %d",&pos,&length);
    getchar();
    char *string1 = (char*)malloc(sizeof (char)*20);
    char *string2 = (char*)malloc(sizeof (char)*20);
    gets (string1);
    string2=extract(string1,pos,length);
    puts (string2);

    return 0;
}
