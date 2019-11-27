#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readSt(int n)
{
    char **a=(char**)(malloc(sizeof(char*)*100));
    int i;
    for(i=0; i<n; i++)
    {
        a[i]=(char*)(malloc(sizeof(char*)*100));
    }
    getchar();
    for(i=0; i<n; i++)
    {
        gets(a[i]);
    }
    return a;
}

int *readInt(int n)
{
    int *a=(int*)(malloc(sizeof(int*)*100));
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    return a;
}

void print(char **a,int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\n%s",a[i]);
    }

}

void swapp(char *a,char *c)
{
    char *b=(char*)(malloc(sizeof(char*)*100));
    strcpy(b,a);
    strcpy(a,c);
    strcpy(c,b);
}

char **autAl(int n,char **author)
{

    char **a=(char**)(malloc(sizeof(char*)*100));
    int i,j;
    for(i=0; i<n; i++)
    {
        a[i]=(char*)(malloc(sizeof(char*)*100));
    }
    for(i=0; i<n; i++)
    {
        strcpy(a[i],author[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(strcmp(a[i],a[j])>0)
            {
                swapp(a[i],a[j]);
            }
        }
    }
    return a;
}

void yearCr(int n,int *year,char **author,char** title)
{
    int i,j,aux;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(year[i]>year[j])
            {
                aux=year[i];
                year[i]=year[j];
                year[j]=aux;
                swapp(author[i],author[j]);
                swapp(title[i],title[j]);
            }
        }
    }
}

int main()
{
    int n,i;
    printf("number of books:");
    scanf("%d",&n);
    printf("\nauthors:");
    char **author=readSt(n);
    printf("\ntitles:");
    char **title=readSt(n);
    printf("\nyears:");
    int *year=readInt(n);
    char **authorAl=autAl(n,author);
    printf("Alphabetical authors:");
    print(authorAl,n);
    yearCr(n,year,author,title);
    printf("Authors by year:");
    print(author,n);
    printf("Titles by year:");
    print(title,n);
}
