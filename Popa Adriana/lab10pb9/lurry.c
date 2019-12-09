#include "lorry.h"

void initializeLorry(lorry *l)
{
    l->name=(char*)(malloc(sizeof(char*)*MAX_NAME_LENGTH));
}

lorry *readLorry(int m)
{
    lorry *l=(lorry*)(malloc(sizeof(lorry*)*m));
    int i;
    getchar();
    for(i=0; i<m; i++)
    {
        initializeLorry(&l[i]);
        printf("give the name of product %d:",i+1);
        gets(l[i].name);
        puts(l[i].name);
        printf("give the amount of product %d:",i+1);
        scanf("%d",&l[i].amount);
        printf("give the price of product %d:",i+1);
        scanf("%f",&l[i].price);getchar();

    }
    return l;
}

void ordDescrec(lorry *l,int m)
{
    int i,ok=0;
    lorry aux;
    while(ok==0)
    {
        ok=1;
        for(i=0;i<m;i++)
        {
            if(l[i].price<l[i+1].price)
            {
                aux=l[i];
                printf("\n%s",aux.name);
                l[i]=l[i+1];
                l[i+1]=aux;
                ok=0;
            }
        }
    }
}

void printLorry(int m,lorry *l)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("\nname:%s \namount:%d \nprice:%f",l[i].name,l[i].amount,l[i].price);
    }
}

void maxValue(int m,lorry *l,int maxLoad)
{
    int i=0;
    ordDescrec(l,m);
    while(l[i].amount<=maxLoad)
    {
        maxLoad=maxLoad-l[i].amount;
        i++;
    }
    if(maxLoad!=0&&i<m-1)
    {
        l[i].amount=maxLoad;
        i++;
    }
    printLorry(i,l);
}
