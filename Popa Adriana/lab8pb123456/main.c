#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt"\nPress a key!"

char *extraction(char *s,int poz,int l)
{
    char *s1=(char*)(malloc(sizeof(char)*100));
    int i;
    for(i=poz; i<l; i++)
        s1[i-poz]=s[i];
    s1[l]='\0';
    return s1;
}

char *insertion(char *s,char *s3,int poz)
{
    char *s2 =(char*)(malloc(sizeof(char)*100));
    int n=strlen(s3),m=strlen(s),i;
    for(i=m+n; i>m; i--)
        s[i]=s[i-1];
    for(i=0; i<n; i++)
        s[i+poz]=s3[i];
    return s;
}

int main()
{
    char *s=(char*)(malloc(sizeof(char)*100));
    int poz=0,l=0;

    //pb2
    printf("introduce the string:");
    gets(s);
    printf("%s",s);
    printf("\nintroduce the position and the length of extracted string:");
    scanf("%d",&poz);
    scanf("%d",&l);
    char *s1 =extraction(s,poz,l);
    printf("\nextarcted string is:%s",s1);
    getchar();

    //pb3
    printf("\nintroduce the string:");
    gets(s);
    char *s3=(char*)(malloc(sizeof(char)*100));
    printf("\nintroduce the inserted string:");
    gets(s3);
    printf("\nintroduce the position of insertted string:");
    scanf("%d",&poz);
    s1=insertion(s,s3,poz);
    printf("\nstring after insertion:%s",s1);
    getchar();


    puts(prompt);
    getchar();
    return 0;
}
