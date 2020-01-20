#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readFile(int *n,FILE *f)
{
    char **a=(char**)(malloc(sizeof(char*)*100));
    int i;
    char *strbuf=(char*)(malloc(sizeof(char*)*100));
    for(i=0; i<10; i++)
    {
        a[i]=(char*)(malloc(sizeof(char*)*100));
    }
    i=0;
    while(fgets(strbuf,100,f)!=NULL)
    {
        puts(strbuf);
        strcpy(a[i],strbuf);
        i++;
    }
    *n=i;
    return a;
}

void printText(int n,char **a,FILE *g)
{
    int i;
    for(i=0; i<n; i++)
    {
        fputs(a[i],g);
        fputs("\n",g);
    }
}

char **compressText(int n,char **a,char character)
{
    int i,j,k,ct;
    for(i=0; i<n; i++)
    {
        ct=1;
        for(j=0; j<strlen(a[i])-1; j++)
        {
            if(a[i][j]==a[i][j+1])
            {
                ct++;
            }
            else
            {
                if(ct>=3)
                {
                    for(k=j; k<strlen(a[i]); k++)
                    {
                        a[i][k-ct+3]=a[i][k];
                    }
                    a[i][k-ct+3]='\0';
                    a[i][j-ct+1]=character;
                    a[i][j-ct+3]=ct+'0';
                    j=j-ct+3;
                }
                ct=1;
            }
        }
    }
    return a;
}

char **decompressText(int n,char **a,char character)
{
    char **b=(char**)(malloc(sizeof(char*)*100));
    int i,j,k,l;
    for(i=0; i<10; i++)
    {
        b[i]=(char*)(malloc(sizeof(char*)*100));
    }
    for(i=0; i<n; i++)
    {
        k=0;
        for(l=0; l<strlen(a[i]); l++)
        {
            if(a[i][l]==character)
            {

                for(j=0; j<(a[i][l+2]-'0'); j++)
                {
                    b[i][k]=a[i][l+1];
                    k++;
                }
                l++;
            }
            else
            {
                if(a[i][l]>'9'||a[i][l]<'0')
                {
                    b[i][k]=a[i][l];
                    k++;
                }

            }
        }
        b[i][k]='\0';
    }

    return b;
}

int main()
{
    FILE *f,*g;
    f=fopen("text1.txt","r");
    g=fopen("text2.txt","w");
    int n=0;

    char **text=readFile(&n,f);
    fputs("The original text is:\n",g);
    printText(n,text,g);
    fputs("\n",g);

    char character;
    printf("give the character:");
    scanf("%c",&character);

    char **compText=compressText(n,text,character);
    fputs("The compressed text is:\n",g);
    printText(n,compText,g);
    fputs("\n",g);

    char **decompText=decompressText(n,compText,character);
    fputs("The decompressed text is:\n",g);
    printText(n,decompText,g);
    fputs("\n",g);
    return 0;
}
