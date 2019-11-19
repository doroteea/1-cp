#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extractSubstring(const char *string1[])
{
    int pos,nr;
    printf("Input the position:\n");
    scanf("%d",&pos);
    printf("Input the number of characters:\n");
    scanf("%d",&nr);
    for(int i=pos; i<pos+nr; i++)
        printf("%c",string1[i]);
        printf("\n");

}


void insertString(const char *string1[],const char *string2[])
{
    int k,j=0;
    printf("Input the position:\n");
    scanf("%d",&k);
    for(int i=strlen(string1)-1; i>=strlen(string1)-k; i--)
    {
        string1[i+strlen(string2)]=string1[i];
    }
    for(int i=k; i<=k+strlen(string2)-1; i++)
    {
        string1[i]=string2[j++];
    }
    puts(string1);
}

void deleteSubstring(const char *string1[])
{
    int pos,nr;
    printf("Input the beginning position:\n");
    scanf("%d",&pos);
    printf("Input the length of the substring:\n");
    scanf("%d",&nr);
    for(int i=pos; i<=pos+nr; i++)
        string1[i]=string1[i+nr];
    for(int i=0; i<strlen(string1); i++)
        printf("%c",string1[i]);
        printf("\n");
}

void substringOfAnotherString(const char *string1[],const char *string2[])
{
    int n=strlen(string1);
    int m=strlen(string2);
    int j=0,ok=0,pos=0;
    for(int i=0; i<n; i++)
    {
        if(string1[i]==string2[j])
        {
            pos=i;
            i++;
            j++;
            while(string1[i]==string2[j])
            {
                i++;
                j++;
            }
            if(j==m-1)
            {
                ok=1;
                printf("The beginning position of the string is %d\n",pos);
            }
            else
            {
                j=0;
            }

        }
    }
    if(ok==0)
    {
        printf("The string is not a substring\n");
    }
}
int main()
{
    char *const string1[50];
    printf("Input the first string:\n");
    gets(string1);
    printf("The first string is:\n");
    puts(string1);

    char *const string2[50];
    printf("\nInput the second string:\n");
    gets(string2);
    printf("The second string is:\n");
    puts(string2);

    printf("\nEXTRACT A SUBSTRING:\n");
    extractSubstring(string1);

    printf("\nINSERT A STRING:\n");
    insertString(string1,string2);

    printf("\nDELETE A SUBSTRING:\n");
    deleteSubstring(string1);

    printf("\nVERIFY IF STRING IS A SUBSTRING OF ANOTHER STRING:\n");
    substringOfAnotherString(string1,string2);
}
