#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_LENGTH=200;
typedef struct
{
    char * name;
    char * country;
    int * nrDiscoveries;
    int * distance;
} explorers;

typedef struct
{
    char * country;
    int * age;
}HolyGrail;

explorers ** initializeExplorers()
{
    explorers ** exp=(explorers**)malloc(sizeof(explorers*)*MAX_LENGTH);
    for(int i=0; i<MAX_LENGTH; i++)
    {
        *(exp+i)=(explorers*)malloc(sizeof(explorers)*MAX_LENGTH);
    }
    for(int i=0; i<MAX_LENGTH; i++)
    {
        exp[i]->name=(char*)malloc(sizeof(char)*MAX_LENGTH);
        exp[i]->country=(char*)malloc(sizeof(char)*MAX_LENGTH);
        exp[i]->nrDiscoveries=(int*)malloc(sizeof(int)*10);
        exp[i]->distance=(int*)malloc(sizeof(int)*10);
    }
    return exp;
}

void readExplorers(explorers ** exp,FILE * f,int n)
{
    char * token=(char*)malloc(sizeof(char)*MAX_LENGTH);
    char * arr=(char*)malloc(sizeof(char)*MAX_LENGTH);
    fgets(arr,MAX_LENGTH,f);
    for(int i=0; i<n; i++)
    {
        fgets(arr,MAX_LENGTH,f);
        arr[strlen(arr)-1]='\0';
        token=strtok(arr,",");
        strcpy(exp[i]->name,token);
        token=strtok(NULL,",");
        strcpy(exp[i]->country,token);
        token=strtok(NULL,",");
        exp[i]->nrDiscoveries=atoi(token);
        token=strtok(NULL,",");
        exp[i]->distance=atoi(token);
    }
}

void printExplorers(explorers ** exp,int n,FILE * f)
{
    for(int i=0; i<n; i++)
    {
        fprintf(f,"%s %s %d %d\n",exp[i]->name,exp[i]->country,exp[i]->nrDiscoveries,exp[i]->distance);
    }
}

void sortDiscoveries(explorers ** exp,int n,FILE * f)
{
    explorers ** aux=initializeExplorers();
    int ok=0;
    while(ok!=1)
    {
        ok=1;
        for(int i=0; i<n-1; i++)
        {
            if(exp[i]->nrDiscoveries<exp[i+1]->nrDiscoveries)
            {
                aux=exp[i];
                exp[i]=exp[i+1];
                exp[i+1]=aux;
                ok=0;
            }
        }
    }
    int m;
    printf("Enter a number m: ");
    scanf("%d",&m);
    fprintf(f,"The explorers sorted based on the number of discoveries are:\n");
    if(m<n)
    {
        printExplorers(exp,n,f);
    }
    else
    {
        printExplorers(exp,n,f);
    }
}

HolyGrail * initializeHolyGrail()
{
    HolyGrail * holy=(HolyGrail*)malloc(sizeof(HolyGrail)*MAX_LENGTH);
    holy->country=(char*)malloc(sizeof(char)*MAX_LENGTH);
    holy->age=(int*)malloc(sizeof(int)*10);
    return holy;
}

void readHolyGrail(HolyGrail * holy, FILE * f2)
{
    char * arr=(char*)malloc(sizeof(char)*MAX_LENGTH);
    char * token=(char*)malloc(sizeof(char)*MAX_LENGTH);
    fgets(arr,MAX_LENGTH,f2);
    arr[strlen(arr)-1]='\0';
    token=strtok(arr,",");
    strcpy(holy->country,token);
    token=strtok(NULL,",");
    holy->age=atoi(token);
}

void printHolyGrail(HolyGrail * holy)
{
    printf("Holy Grail is: %s %d\n",holy->country,holy->age);
}

void sortDistance(FILE * f,explorers ** exp,int n,HolyGrail * holy)
{
    explorers ** aux=initializeExplorers();
    int ok=0;
    while(ok!=1)
    {
        ok=1;
        for(int i=0;i<n;i++)
        {
            if(exp[i]->distance>exp[i+1]->distance)
            {
                aux=exp[i];
                exp[i]=exp[i+1];
                exp[i+1]=aux;
                ok=0;
            }
        }
    }
    fprintf(f,"The explorers sorted based on their distance to the Holy Grail:\n");
    printExplorers(exp,n,f);
}
int main()
{
    explorers ** exp=initializeExplorers();
    FILE * f1=fopen("explorers.dat","r");
    FILE * f2=fopen("holyGrail.dat","r");
     FILE * f3=fopen("discoveriesExplorers.dat","w");
    FILE * f4=fopen("grailExplorers.dat","w");
    int n;
    fscanf(f1,"%d",&n);
    readExplorers(exp,f1,n);
    printExplorers(exp,n,f3);
    sortDiscoveries(exp,n,f3);
    HolyGrail * holy=initializeHolyGrail();
    readHolyGrail(holy,f2);
    sortDistance(f4,exp,n,holy);
}
