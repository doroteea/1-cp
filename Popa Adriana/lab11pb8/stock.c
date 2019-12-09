#include "stock.h"

void initializeStocks(stocks *s)
{
    s->name=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
}

int charToInt(char *p)
{
    int nr=0,i=0;
    while(p[i]!=NULL)
    {
        nr=nr*10+p[i]-'0';
        i++;
    }
    return nr;
}

char *intToChar(int n)
{
    char *p=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    int i=0;
    int ct=1,aux=n;
    while(aux>0)
    {
        ct=ct*10;
        aux=aux/10;
    }
    ct=ct/10;
    while(n>0)
    {
        p[i]='0'+n/ct;
        n=n%ct;
        ct=ct/10;
        i++;
    }
    return p;

}

stocks *readStocks(int *n,FILE *f)
{
    int i=0;
    stocks *s=(stocks*)(malloc(sizeof(stocks*)*MAX_LENGTH));
    char *p=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    char *strbuf=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    while(fgets(strbuf,MAX_LENGTH,f)!=NULL)
    {
        puts(strbuf);
        initializeStocks(&s[i]);
        p=strtok(strbuf," ");
        s[i].code=charToInt(p);
        p=strtok(NULL," ");
        strcpy(s[i].name,p);
        p=strtok(NULL," ");
        s[i].price=charToInt(p);
        i++;
    }
    *n=i;
    return s;
}


void printStock(int n,stocks *s,FILE *f)
{
    int i;
    char *p=(char*)(malloc(sizeof(char*)*MAX_LENGTH));

    for(i=0; i<n; i++)
    {
        fputs("\n",f);
        fputs("Product code:",f);
        p=intToChar(s[i].code);
        fputs(p,f);
        fputs("\n",f);
        fputs("Product name:",f);
        fputs(s[i].name,f);
        fputs("\n",f);
        fputs("Product price:",f);
        p=intToChar(s[i].price);
        fputs(p,f);
        fputs("\n",f);
    }
}

stocks *commonStock(int n,int m,stocks *s1,stocks *s2,int *l)
{
    int i=0,j=0,k=0;
    stocks *c=(stocks*)(malloc(sizeof(stocks*)*MAX_LENGTH));
    while(i<n&&j<m)
    {
        initializeStocks(&c[k]);
        if(s1[i].code<s2[j].code)
        {
            c[k]=s1[i];
            k++;
            i++;
        }
        else
        {
            if(s1[i].code>s2[j].code)
            {
                c[k]=s2[j];
                k++;
                j++;
            }
            else
            {
                c[k]=s2[j];
                k++;
                j++;
                i++;

            }
        }
    }
    while(i<n)
    {
        initializeStocks(&c[k]);
        c[k]=s1[i];
        i++;
        k++;
    }
    while(j<m)
    {
        initializeStocks(&c[k]);
        c[k]=s2[j];
        j++;
        k++;
    }
    *l=k;
    return c;
}

stocks *changePrice(stocks *s)
{
    int i,ct,newprice,poz;
    printf("Give the number of changes you want to make:");
    scanf("%d",&ct);
    for(i=0; i<ct; i++)
    {
        printf("\nGive the order number:");
        scanf("%d",&poz);
        printf("Give the new price");
        scanf("%d",&newprice);
        s[poz].price=newprice;
    }
    return s;
}
