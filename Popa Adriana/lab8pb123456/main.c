#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define prompt "\nPress a key!"

char *extraction(char *s,int poz,int l)
{
    char *s1=(char*)(malloc(sizeof(char)*100));
    int i,k=0,n;
    char a;
    n=strlen(s);
    for(i=poz; i<n&&k<l; i++)
    {
        a=s[i];
        s1[k++]=a;
    }
    s1[l]='\0';
    return s1;
}

void pb2()
{
    char *s=(char*)(malloc(sizeof(char)*100));
    int poz=0,l=0;
    printf("introduce the string:");
    gets(s);
    printf("\nintroduce the position and the length of extracted string:");
    scanf("%d",&poz);
    scanf("%d",&l);
    char *s1 =extraction(s,poz,l);
    printf("\nextarcted string is:%s",s1);
    getchar();
}

char *insertion(char *s,char *s3,int poz)
{
    int n=strlen(s3),m=strlen(s),i;
    char a;
    for(i=m; i<m+n; i++)
        s[i]=' ';
    s[m+n]=NULL;
    for(i=m+n; i>poz; i--)
    {
        a=s[i-poz];
        s[i]=a;
    }
    for(i=0; i<n; i++)
    {
        a=s3[i];
        s[i+poz]=a;
    }
    s[m+n]='\0';
    return s;
}

void pb3()
{
    char *s=(char*)(malloc(sizeof(char)*100)),*s1=(char*)(malloc(sizeof(char)*100));
    int poz=0;
    printf("\nintroduce the string:");
    gets(s);
    printf("\nintroduce the inserted string:");
    gets(s1);
    printf("\nintroduce the position of insertted string:");
    scanf("%d",&poz);
    s1=insertion(s,s1,poz);
    printf("\nstring after insertion:%s",s1);
    getchar();

}

char *deleteSubSt(char *s,char *s3)
{
    int i,ct,n,m,j,k;
    n=strlen(s);
    m=strlen(s3);
    char b=s3[0];
    for(i=0; i<n; i++)
    {
        char a=s[i];
        if(a==b)
        {

            ct=0;
            j=i;
            a=s[j];
            k=0;
            b=s3[k];
            while(a==b)
            {
                ct++;
                k++;
                j++;
                a=s[j];
                b=s3[k];
            }
            if(ct==m)
            {
                strcpy(s+i,s+j);
                return s;
            }
        }
    }
    return s;
}

void pb4()
{
    char *s=(char*)(malloc(sizeof(char)*100)),*s1=(char*)(malloc(sizeof(char)*100));
    printf("\nintroduce the string:");
    gets(s);
    printf("\nintroduce the substring:");
    gets(s1);
    s1=deleteSubSt(s,s1);
    printf("\nstring after deleting:%s",s1);
    getchar();
}

int verifSubSt(char *s,char *s3)
{
    int n,m,i,ct,k,j;
    char a,b;
    b=s3[0];
    n=strlen(s);
    m=strlen(s3);
    for(i=0; i<n; i++)
    {
        a=s[i];
        if(a==b)
        {

            ct=0;
            j=i;
            a=s[j];
            k=0;
            b=s3[k];
            while(a==b)
            {
                ct++;
                k++;
                j++;
                a=s[j];
                b=s3[k];
            }
            if(ct==m)
                return i;
        }
    }
    return -1;
}

void pb5()
{
    char *s=(char*)(malloc(sizeof(char)*100)),*s1=(char*)(malloc(sizeof(char)*100));
    int poz=0;
    printf("\nintroduce the string:");
    gets(s);
    printf("\nintroduce the substring:");
    gets(s1);
    poz=verifSubSt(s,s1);
    if(poz==-1)
        printf("your string is not a substring ");
    else
        printf("your substring was found on position %d",poz);
    getchar();
}

char *intToChar(int l)
{
    char *s=(char*)(malloc(sizeof(char)*100));
    *s=l+32;
    return s;
}

int charToInt(char *s)
{
    int a;
    a=s[0]-32;
    return a;
}

void pb6()
{
    char *s=(char*)(malloc(sizeof(char)*100)),*s1=(char*)(malloc(sizeof(char)*100));
    int nr=0;
    printf("\nintroduce the number:");
    scanf("%d",&nr);
    s1=intToChar(nr);
    printf("\n:%s",s1);
    getchar();
    printf("\nintroduce the string:");
    gets(s);
    nr=charToInt(s);
    printf("%d",nr);
}


int main()
{
    pb2();
    pb3();
    pb4();
    pb5();
    pb6();

    puts(prompt);
    getchar();
    return 0;
}
