#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert(char *destination,char *source,int position)
{
    int i,j,k=0;
    for(i=strlen(destination)-1;i>=position;i--)
    {
        destination[i+strlen(source)]=destination[i];
    }
    for(j=position;j<position+strlen(source);j++)
    {
        destination[i]=source[k];
        k++;
    }
    destination[strlen(destination)+strlen(source)]='\0';
    puts(destination);
}
int main()
{
    char *destination,*source;
    int position;
    *destination=(char *)malloc(sizeof(char)*200);
    *source=(char *)malloc(sizeof(char)*100);
    printf("Enter destination string:\n");
    gets(destination);
    printf("Enter source string:\n");
    gets(source);
    printf("Enter position:\n");
    scanf("%d",&position);
    printf("The string is:\n");`
    insert(destination,source,position);



    return 0;
}
