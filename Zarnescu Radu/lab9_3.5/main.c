#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void verify(char *string1, char *string2)
{
    int i,j,length1,length2,ind=0;
    length1=strlen(string1);
    length2=strlen(string2);
    for(i=0;i<length1;i++)
    {
        if(string1[i]==string2[0])
        {
            ind=1;
            for(j=1;j<length2 && ind==1;j++)
            {
                if(string1[i+j]!=string2[j])
                {
                    ind=0;
                }
            }
        }
    }
    if(ind)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
int main()
{
    printf("Is string2 a substring of string1?\n");
    char *string1=(char*)malloc(sizeof(char)*20);
    char *string2=(char*)malloc(sizeof(char)*20);
    printf("insert string1:\n");
    gets(string1);
    printf("insert string2:\n");
    gets(string2);
    verify(string1,string2);
    return 0;
}
