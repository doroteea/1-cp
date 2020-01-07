#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct
{
    char *name;
    char *country;
    char *discoveries;
    char *distance;
} explorers;

void initializeExplorers(explorers *e)
{
    e->name=(char*)malloc(sizeof(char)*MAX);
    e->country=(char*)malloc(sizeof(char)*MAX);
    e->discoveries=(char*)malloc(sizeof(char)*MAX);
    e->distance=(char*)malloc(sizeof(char)*MAX);
}

void sortByDiscoveries(explorers *e,int nrOfExplorers)
{
    explorers aux;
    for(int i=0;i<nrOfExplorers;i++)
    {
        for(int j=i+1;j<nrOfExplorers;j++)
        {
            if(atoi(e[i].discoveries)<atoi(e[j].discoveries))
            {
                aux=e[i];
                e[i]=e[j];
                e[j]=aux;
            }
        }
    }
}

void readGrail(FILE *f,char *grailCountry,char *grailAge)
{
    char *p=(char*)malloc(sizeof(char)*MAX);
    fgets(p,MAX,f);
    strcpy(grailCountry,strtok(p,","));
    strcpy(grailAge,strtok(NULL,","));
}

void sortByDistance(explorers *e,int nrOfExplorers)
{
     explorers aux;
    for(int i=0;i<nrOfExplorers;i++)
    {
        for(int j=i+1;j<nrOfExplorers;j++)
        {
            if(atoi(e[i].distance)>atoi(e[j].distance))
            {
                aux=e[i];
                e[i]=e[j];
                e[j]=aux;
            }
        }
    }
}

int main()
{
    FILE *f=fopen("explorers.dat","r");
    FILE *f2=fopen("holyGrail.dat","r");
    FILE *g=fopen("grailExplorers.dat","w");
    FILE *h=fopen("distanceExplorers.dat","w");
    int nrOfExplorers;
    fscanf(f,"%d\n",&nrOfExplorers);
    explorers *explorer=(explorers*)malloc(sizeof(explorers)*nrOfExplorers);
    for(int i=0;i<nrOfExplorers;i++)
    {
        initializeExplorers(&explorer[i]);
    }
    char *strbuf=(char*)malloc(sizeof(char)*MAX);
    for(int i=0; i<nrOfExplorers; i++)
    {
        fgets(strbuf,MAX,f);
        strcpy(explorer[i].name,strtok(strbuf,","));
        strcpy(explorer[i].country,strtok(NULL,","));
        strcpy(explorer[i].discoveries,strtok(NULL,","));
        strcpy(explorer[i].distance,strtok(NULL,","));
    }

    sortByDiscoveries(explorer,nrOfExplorers);
    for(int i=0;i<nrOfExplorers;i++)
    {
            fprintf(g,"%s,%s,%s,%s",explorer[i].name,explorer[i].country,explorer[i].discoveries,explorer[i].distance);
    }
    char *grailCountry=(char*)malloc(sizeof(char)*MAX);
    char *grailAge=(char*)malloc(sizeof(char)*MAX);
    readGrail(f2,grailCountry,grailAge);
    printf("The fuckin holy grail nibba is in %s and is %d years old.",grailCountry,atoi(grailAge));
    sortByDistance(explorer,nrOfExplorers);
    for(int i=0;i<nrOfExplorers;i++)
    {
            fprintf(h,"%s,%s,%s,%s",explorer[i].name,explorer[i].country,explorer[i].discoveries,explorer[i].distance);
    }
    return 0;
}
