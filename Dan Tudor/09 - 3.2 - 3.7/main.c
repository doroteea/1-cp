#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char s[30], int n, int m)
{
    char sub[30];
    int i;
    strncpy(sub,s+n,m);
    puts(sub);
}

void insertString(char s1[30], char s2[30], int i)
{
    strcpy(s1+i, s2);
    puts(s1);
}

void deleteSubstring(char s1[30], int i, int j)
{
    strcpy(s1+i,s1+i+j);
    puts(s1);
}

void checkSubstring(char s1[30], char s2[30])
{
    char aux[30];
    for(int i=0; i<strlen(s1)-strlen(s2); i++)
    {
        strncpy(aux,s1+i,strlen(s2));
        aux[strlen(s2)] = '\0';
        //puts(aux);
        if(strcmp(aux,s2) == 0)
        {
            printf("da %d\n",i);
            break;
        }
    }
}

void charToInt(char c[30])
{
    int n=0,p=1;
    for(int i=strlen(c)-1; i>=0; i--)
    {
        int k = c[i]-'0';
        n = k*p+n;
        p = p*10;
    }
    printf("%d\n",n);
}
void intToChar(int i)
{
    char s[30];
    int dim=0;
    while(i>0)
    {
        int c = i%10;
        i /= 10;
        s[dim] = c+'0';
        dim++;
    }
    for(i=0; i<dim/2; i++)
    {
        char aux;
        aux = s[i];
        s[i] = s[dim-1-i];
        s[dim-1-i] = aux;
    }
    s[dim]='\0';
    puts(s);
}

void longestAndBiggest(char s[30][30], int n)
{
    char longest[30]="";
    char maxim[30]="a";
    int lmax=0;
    for(int i=0; i<n; i++)
    {
        if(strlen(s[i])>lmax)
        {
            lmax = strlen(s[i]);
            //longest[] = "";
            strcpy(longest,s[i]);
        }
        if(strcmp(s[i],maxim) > 0)
        {
            //maxim[]="";
            strcpy(maxim,s[i]);
        }
    }
    puts(longest);
    puts(maxim);
}

int main()
{
    char string1[30];
    char string2[30];
    int n,m,k;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    gets(string1);
    gets(string2);
    substring(string1,n,m);
    insertString(string1, string2, m);
    deleteSubstring(string1,m,k);
    char s1[30],s2[30];
    gets(s1);
    gets(s2);
    checkSubstring(s1,s2);
    charToInt("200");
    intToChar(250);
    char s[30][30];
    for(int i=0; i<n; i++)
    {
        gets(s[i]);
    }
    longestAndBiggest(s,n);
    return 0;
}
