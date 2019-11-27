#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX_LENGTH = 200;
typedef struct
{
    int code;
    char *name;
    char *unitOfMeasure;
    int amount;
    double price;
}items;

double convertStringIntoNumber (char *sourceString)
{
    double p=1.0;
    double number=0.0;
    bool dot=false;
    int size=strlen(sourceString);
    size--;
    for (int i=0; i<size; i++)
    {
        if (sourceString[i]=='.')
        {
            dot=true;
            p/=10;
        }
        else if (dot==false)
        {
            number=number*10+(sourceString[i]-'0');
        }
        else
        {
            number=number+(sourceString[i]-'0')*p;
            p/=10;
        }
    }
    return number;
}

void function(char *strbuf, items *item)
{
    char *aux = (char*)malloc(sizeof(char)*MAX_LENGTH);
    char *p;
    p=strtok(strbuf, ", ");
    strcpy(aux, p);
    int i=0, len=strlen(aux);
    item->code=0;
    while (i<len)
    {
        item->code=item->code*10+(aux[i]-'0');
        i++;
    }

    p=strtok(NULL, ", ");
    item->name=(char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy(item->name, p);

    p=strtok(NULL, ", ");
    item->unitOfMeasure=(char*)malloc(sizeof(char)*MAX_LENGTH);
    strcpy(item->unitOfMeasure, p);

    p=strtok(NULL, ", ");
    strcpy(aux, p);
    i=0; len=strlen(aux);
    item->amount=0;
    while (i<len)
    {
        item->amount=item->amount*10+(aux[i]-'0');
        i++;
    }

    p=strtok(NULL, ", ");
    strcpy(aux, p);
    item->price=convertStringIntoNumber(aux);

}

int main()
{
    FILE *f=fopen("text.in", "r");

    char *strbuf = (char*)malloc(sizeof(char)*MAX_LENGTH);
    items *item = (items*)malloc(sizeof(items)*MAX_LENGTH);

    int nrOfItems=0;
    while (fgets(strbuf, MAX_LENGTH, f)!=NULL)
    {
            function(strbuf, item+nrOfItems);
            nrOfItems++;
    }
    fclose(f);

    for (int i=0; i<nrOfItems; i++)
    {
        printf("%d %s %s %d %lf\n", item[i].code, item[i].name, item[i].unitOfMeasure, item[i].amount, item[i].price);
    }

    return 0;
}
