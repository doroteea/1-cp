#include "cars.h"

void initializeCars(cars *c)
{
    c->brand=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    c->owner=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    c->colour=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    c->number=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
}

cars *readCars(int *n)
{
    FILE *f;
    f=fopen("cars.txt","r");
    int i=0;
    cars *c=(cars*)(malloc(sizeof(cars*)*100));
    char *p=(char*)(malloc(sizeof(char*)*MAX_LENGTH));
    char *strbuf=(char*)(malloc(sizeof(char*)*MAX_LENGTH));

    while(fgets(strbuf,MAX_LENGTH,f)!=NULL)
    {
        puts(strbuf);
        initializeCars(&c[i]);
        p=strtok(strbuf," ");
        strcpy(c[i].brand,p);
        p=strtok(NULL," ");
        strcpy(c[i].owner,p);
        p=strtok(NULL," ");
        strcpy(c[i].colour,p);
        p=strtok(NULL," ");
        strcpy(c[i].number,p);
        i++;
    }
    *n=i;
    fclose(f);
    return c;
}

void printCars(int n,cars *c)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nBrand: %s\nOwner: %s\nColour: %s\nNumber: %s\n",c[i].brand,c[i].owner,c[i].colour,c[i].number);
    }
}

cars *sortCars(int n,cars *c)
{
    int i,ok=0;
    cars aux;
    initializeCars(&aux);
    while(ok==0)
    {
        ok=1;
        for(i=0; i<n-1; i++)
        {
            if(strcmp(c[i].colour,c[i+1].colour)==1)
            {
                aux=c[i];
                c[i]=c[i+1];
                c[i+1]=aux;
               ok=0;
            }
            else
            {
                if(strcmp(c[i].colour,c[i+1].colour)==0&&strcmp(c[i].owner,c[i+1].owner)==1)
                {
                    aux=c[i];
                    c[i]=c[i+1];
                    c[i+1]=aux;
                    ok=0;
                }
            }
        }
    }
    return c;
}
