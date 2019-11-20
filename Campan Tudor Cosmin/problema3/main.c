#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[100],subs[100];
    int poz=-1,lenght;
    scanf("%s %s",s,subs);
    lenght=strlen(subs);
    for(int i=0; i<=strlen(s); i++)
        if(strncmp(s+i,subs,lenght)==0)
        {
            poz=i;
            strcat(s+i,s+i+lenght);
        }
    if(poz==-1)
        printf("nu exista subsirul in sir");
    else
        printf("%s %d %d",s,poz,lenght);
    return 0;
}
