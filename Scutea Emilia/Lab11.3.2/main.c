#include <stdio.h>
#include <stdlib.h>

const int MAX_LENGTH = 200;
typedef struct
{
    char *code;
    char *name;
    char* measureUnit;
    int amount;
    int priceUnit;
} item;

void initializeList(item *a)
{
    a->code=(char*)malloc(sizeof(char)*30);
    a->name=(char*)malloc(sizeof(char)*30);
    a->measureUnit=(char*)malloc(sizeof(char)*30);
}

void *readItem(item *a,int n)
{
    FILE *f;
    f=fopen("item.txt","rw");
    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);
    int i=0;
    initializeList(&a[i]);
    while(fgets(strbuf, MAX_LENGTH, f) != NULL)
    {
        puts(strbuf);
        char *p=strtok(strbuf," ");
        strcpy(a[i].code,p);
        p=strtok(NULL,strbuf);
        strcpy(a[i].name,p);
        p=strtok(NULL,strbuf);
        strcpy(a[i].measureUnit,p);
        p=strtok(NULL,strbuf);
        strcpy(a[i].amount,p);
        p=strtok(NULL,strbuf);
        strcpy(a[i].priceUnit,p);
        p=strtok(NULL,strbuf);
        i++;
        printf("code:%s, name:%s, measureUnit:%s, amount:%d, priceUnit:%d",a[i].code,a[i].name,a[i].measureUnit,a[i].amount,a[i].priceUnit);

    }
    n=i;
    fclose(f);
}
int main()
{
    item *a=(int*)malloc(sizeof(int)*30);
    int n=0;
    readItem(a,n);
}
