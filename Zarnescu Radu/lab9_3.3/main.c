#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insert(char *string1,char *string2,int position)
{
    int i,j,k;
    for(i=position,j=position+strlen(string2),k=0;i<position+strlen(string2),k<strlen(string2);i++,k++,j++)
    {
        string1[j]=string1[i];
        string1[i]=string2[k];
    }
}
int main()
{
    printf("Hello world!\n");
    int position;
    scanf("%d",&position);
    getchar();
    char *string1 = (char*)malloc(sizeof(char)*40);
    char *string2 = (char*)malloc(sizeof(char)*20);
    gets (string1);
    gets (string2);
    insert(string1,string2,position);
    puts (string1);
    return 0;
}
