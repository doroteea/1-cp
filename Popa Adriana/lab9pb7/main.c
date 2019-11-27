#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read(int n)
{
    char **s=(char**)(malloc(sizeof(char*)*100));
    int i;
    for(i=0; i<n; i++)
    {
        s[i]=(char*)(malloc(sizeof(char*)*100));
    }
    getchar();
    for(i=0; i<n; i++)
    {
        gets(s[i]);
    }
    return s;
}

char *longestSt(char **s,int n)
{
    int m,max=-1,i;
    char *l=(char*)(malloc(sizeof(char*)*100));
    for(i=0; i<n; i++)
    {
        m=strlen(s[i]);
        if(m>max)
        {
            max=m;
            strcpy(l,s[i]);
        }
    }
    return l;
}

char *biggestSt(char **s,int n)
{
    char *l=(char*)(malloc(sizeof(char*)*100));
    l="0";
    int i,j,k=0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            k=(int)(strcmp(s[i],s[j]));
            if(k>=0)
            {
                k=(int)(strcmp(s[i],l));
                if(k>=0)
                {
                    strcpy(l,s[i]);
                }
            }
            else
            {
                k=(int)(strcmp(s[j],l));
                if(k>=0)
                {
                    strcpy(l,s[j]);
                }
            }
        }
    }
    return l;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    char **s=read(n);
    char *l=(char*)(malloc(sizeof(char*)*100));
    l=longestSt(s,n);
    printf("longest string is: %s",l);
    l=biggestSt(s,n);
    printf("biggest string is: %s",l);
    return 0;
}
