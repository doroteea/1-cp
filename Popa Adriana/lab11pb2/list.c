#include "list.h"

int n;

void initializeList(items *l)
{
    l->code=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    l->name=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    l->measure=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
}

items *readList()
{
    FILE *f;
    f=fopen("list.txt","rw+");
    items *a=(items*)(malloc(sizeof(items*)*100));

    int i=0;
    char *p=(char*) malloc(sizeof(char*)*100);;
    char *strbuf=(char*) malloc(sizeof(char*)*100);

    while(fgets(strbuf, 100, f) != NULL)
    {
        puts(strbuf);
        initializeList(&a[i]);
        p=strtok(strbuf," ");
        strcpy(a[i].code,p);
        p=strtok(NULL," ");
        strcpy(a[i].name,p);
        p=strtok(NULL," ");
        strcpy(a[i].measure,p);
        p=strtok(NULL," ");
        a[i].amount=atoi(p);
        p=strtok(NULL," ");
        a[i].price=atoi(p);
        i++;
    }
    n=i;
    fclose(f);
    return a;
}

void printList(items *a)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("code:%s\nname:%s\nmeasure:%s\namount:%d\nprice:%d\n\n",a[i].code,a[i].name,a[i].measure,a[i].amount,a[i].price);
    }
}

items *sort(items *a)
{
    items aux;
    initializeList(&aux);
    int ok,i;
    ok=0;
    while(ok==0)
    {
        ok=1;
        for(i=0; i<n-1; i++)
        {
            if(strcmp(a[i].code,a[i+1].code)<1)
            {
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                ok=0;
            }
        }
    }
    return a;
}

items *introduceItems(int *poz,items *c,items *a,int m)
{
    int i,k=0;
    while(m!=0)
    {
        n++;
        for(i=n; i>poz[k]; i--)
        {
            printf("%d",i);
            a[i]=a[i-1];
        }
        a[poz[k]]=c[k];
        k++;
        m--;
    }
    return a;
}

items *readItems(int m)
{
    items *c=(items*)(malloc(sizeof(items*)*MAX_LENGTH));
    int i;
    for(i=0; i<m; i++)
    {
        getchar();
        initializeList(&c[i]);
        printf("Give the code of item:");
        gets(c[i].code);
        printf("Give the name of item:");
        gets(c[i].name);
        printf("Give the measure unit:");
        gets(c[i].measure);
        printf("Give the amount:");
        scanf("%d",&c[i].amount);
        printf("Give the price:");
        scanf("%d",&c[i].price);
    }
    return c;
}

items *deleteItems(items *a,int m)
{
    char **names=(char**)(malloc(sizeof(char*)*100));
    int i,j,k;
    for(i=0; i<n; i++)
    {
        names[i]=(char*)(malloc(sizeof(char*)*100));
    }
    printf("Give the name of products you want to delete:\n");
    getchar();
    for(i=0; i<m; i++)
    {
        gets(names[i]);
    }
    for(i=0; i<n; i++)
    {

        for(k=0; k<m; k++)
        {
            if(strstr(a[i].name,names[k])!=NULL)
            {
                for(j=i; j<n-1; j++)
                {
                    a[j]=a[j+1];
                }
                n--;
            }
        }
    }
    return a;
}
