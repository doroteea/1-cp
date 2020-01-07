#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPLORERS 20
#define MAX_STRING_LENGTH 50
#define MAX_ROW_LENGTH 100

typedef struct
{
    char* name;
    char* country;
    int discoveries;
    int distance;
}explorerType;

void initializeExplorers(explorerType *exp)
{
    exp->name=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
    exp->country=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
}
void fillExplorerVector(explorerType *explorers, int N, FILE *f)
{
    char *p;
    char* strbuf=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    for(int i=0;i<N;i++)
    {
        fgets(strbuf,MAX_ROW_LENGTH,f);
        p=strtok(strbuf,",");
        strcpy(explorers[i].name,p);
        p=strtok(NULL,",\n");
        strcpy(explorers[i].country,p);
        p=strtok(NULL,",\n");
        explorers[i].discoveries=0;
        explorers[i].distance=0;
        for(int j=0;j<strlen(p);j++)
        {
            explorers[i].discoveries=explorers[i].discoveries*10+(p[j]-'0');
        }
        p=strtok(NULL,",\n");
        for(int j=0;j<strlen(p);j++)
        {
            explorers[i].distance=explorers[i].distance*10+(p[j]-'0');
        }
    }
}
void sortByDiscoveries(explorerType *explorers,int N)
{
    explorerType aux;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(explorers[i].discoveries<explorers[j].discoveries)
            {
                aux=explorers[i];
                explorers[i]=explorers[j];
                explorers[j]=aux;
            }
        }
    }
}
void sortByDistance(explorerType *explorers,int N)
{
    explorerType aux;
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(explorers[i].distance>explorers[j].distance)
            {
                aux=explorers[i];
                explorers[i]=explorers[j];
                explorers[j]=aux;
            }
        }
    }
}
void printExplorers(explorerType *explorers,int N, FILE *f)
{
    for(int i=0;i<N;i++)
    {
        fprintf(f,"%s,%s,%d,%d\n",explorers[i].name,explorers[i].country,explorers[i].discoveries,explorers[i].distance);
    }
}
void readGrailDetails(FILE *g,char* grailCountry, int *grailAge)
{
    char* strbuf=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    char *p;
    fgets(strbuf,MAX_ROW_LENGTH,g);
    p=strtok(strbuf,",");
    strcpy(grailCountry,p);
    p=strtok(NULL,"\n");
    for(int i=0;i<strlen(p);i++)
    {
        *grailAge=*grailAge*10+(p[i]-'0');
    }

}
int main()
{
    FILE *f=fopen("explorers.dat","r");
    FILE *g=fopen("holyGrail.dat","r");
    FILE *ff=fopen("discoveriesExplorers.dat","w");
    FILE *gg=fopen("grailExplorers.dat","w");
    int N;
    fscanf(f,"%d\n",&N);
    explorerType *explorers=(explorerType*)malloc(sizeof(explorerType)*MAX_EXPLORERS);
    for(int i=0;i<N;i++)
    {
        initializeExplorers(&explorers[i]);
    }
    fillExplorerVector(explorers,N,f);
    sortByDiscoveries(explorers,N);
    int m;printf("Please input m\n");scanf("%d",&m);
    if(m>N)
    {
        m=N;
    }
    printExplorers(explorers,m,ff);

    char *grailCountry=(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    int grailAge=0;
    readGrailDetails(g,grailCountry,&grailAge);
    printf("The Holy Grail is a %d year old aftefact that originates from %s",grailAge,grailCountry);

    sortByDistance(explorers,N);
    printExplorers(explorers,N,gg);

    fclose(f);fclose(g);fclose(ff);fclose(gg);
    return 0;
}
