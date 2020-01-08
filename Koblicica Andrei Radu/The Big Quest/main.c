#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REQ_EXP 100
#define MAX_LINES 20
#define MAX_ROW_LENGTH 100
#define MAX_STR_LENGTH 50
typedef struct
{
    char* name;
    char type;
    int damage;
} heroType;
typedef struct
{
    char *title;
    int *typeVector;
    int damage;
    int xp;
} questType;
void defineHeroes(heroType *h)
{
    h->name=(char*)malloc(sizeof(char)*MAX_STR_LENGTH);
}
void defineQuests(questType *q)
{
    q->title=(char*)malloc(sizeof(char)*MAX_STR_LENGTH);
    q->typeVector=(int*)malloc(sizeof(int)*3);
}
void formHeroArray(heroType *heroes, FILE *f, int *nrOfHeroes)
{
    char * strbuf =(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    char *p;
    while(fgets(strbuf,MAX_ROW_LENGTH,f))
    {
        p=strtok(strbuf,",");
        strcpy(heroes[*nrOfHeroes].name,p);
        p=strtok(NULL,",");
        heroes[*nrOfHeroes].type=p[0];
        p=strtok(NULL,"\n");
        heroes[*nrOfHeroes].damage=0;
        for(int i=0; i<strlen(p); i++)
        {
            heroes[*nrOfHeroes].damage=heroes[*nrOfHeroes].damage*10+(p[i]-'0');
        }
        (*nrOfHeroes)++;
    }
}
void formQuestArray(questType *quests,FILE *g, int *nrOfQuests)
{
    char * strbuf =(char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
    char *p;
    while(fgets(strbuf,MAX_ROW_LENGTH,g))
    {
        p=strtok(strbuf,",");
        strcpy(quests[*nrOfQuests].title,p);
        p=strtok(NULL,",");
        quests[*nrOfQuests].typeVector[0]=0;
        quests[*nrOfQuests].typeVector[1]=0;
        quests[*nrOfQuests].typeVector[2]=0;
        for(int i=0; i<strlen(p); i++)
        {
            if(p[i]=='D')
            {
                quests[*nrOfQuests].typeVector[0]++;
            }
            if(p[i]=='H')
            {
                quests[*nrOfQuests].typeVector[1]++;
            }
            if(p[i]=='T')
            {
                quests[*nrOfQuests].typeVector[2]++;
            }
        }
        p=strtok(NULL,",");
        quests[*nrOfQuests].damage=0;
        for(int i=0; i<strlen(p); i++)
        {
            quests[*nrOfQuests].damage=quests[*nrOfQuests].damage*10+(p[i]-'0');
        }
        p=strtok(NULL,"\n");
        quests[*nrOfQuests].xp=0;
        for(int i=0; i<strlen(p); i++)
        {
            quests[*nrOfQuests].xp=quests[*nrOfQuests].xp*10+(p[i]-'0');
        }
        (*nrOfQuests)++;
    }
}
void sortHeroArray(heroType *heroes, int nrOfHeroes)
{
    heroType aux;
    for(int i=0; i<nrOfHeroes; i++)
    {
        for(int j=i+1; j<=nrOfHeroes; j++)
        {
            if(heroes[i].damage<heroes[j].damage)
            {
                aux=heroes[i];
                heroes[i]=heroes[j];
                heroes[j]=aux;
            }
        }
    }
}
void fillHeroTypeVector(int *heroTypeVector, heroType *heroes, int nrOfHeroes)
{
    heroTypeVector[0]=0;
    heroTypeVector[1]=0;
    heroTypeVector[2]=0;
    for(int j=0; j<nrOfHeroes; j++)
    {
        if(heroes[j].type=='D')
        {
            heroTypeVector[0]++;
        }
        if(heroes[j].type=='H')
        {
            heroTypeVector[1]++;
        }
        if(heroes[j].type=='T')
        {
            heroTypeVector[2]++;
        }

    }
}
int areThereEnoughHeroes(questType *quests, int questNr, int *heroTypeVector)
{
    if(heroTypeVector[0]>=quests[questNr].typeVector[0] && heroTypeVector[1]>=quests[questNr].typeVector[1] && heroTypeVector[2]>=quests[questNr].typeVector[2])
    {
        return 3;
    }
    else
    {
        if(heroTypeVector[0]<quests[questNr].typeVector[0])
        {
            return 0;
        }
        else
        {
            if(heroTypeVector[1]<quests[questNr].typeVector[1])
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}
void calculateDamageTotal(heroType *heroes, questType *quests, int nrOfHeroes, int nrOfQuests, int *damageTotal,int i, char * names)
{
    int c;

    strcpy(names," ");
    c=quests[i].typeVector[0];
    for(int k=0; k<nrOfHeroes&&c>0; k++)
    {
        if(heroes[k].type=='D')
        {
            *damageTotal+=heroes[k].damage;
            strcat(names,heroes[k].name);
            strcat(names,", ");
            c--;
        }
    }
    c=quests[i].typeVector[1];
    for(int k=0; k<nrOfHeroes&&c>0; k++)
    {
        if(heroes[k].type=='H')
        {
            *damageTotal+=heroes[k].damage;
            strcat(names,heroes[k].name);
            strcat(names,", ");
            c--;
        }
    }
    c=quests[i].typeVector[2];
    for(int k=0; k<nrOfHeroes&&c>0; k++)
    {
        if(heroes[k].type=='T')
        {
            *damageTotal+=heroes[k].damage;
            strcat(names,heroes[k].name);
            strcat(names,", ");
            c--;
        }
    }
}
void doQuests(heroType *heroes, questType *quests, int nrOfHeroes, int nrOfQuests, int *heroTypeVector, int *totalXP,FILE *o)
{

    for(int i=0; i<nrOfQuests; i++)
    {
        if(areThereEnoughHeroes(quests,i,heroTypeVector)==3)
        {
            int damageTotal=0;
            char *names = (char*)malloc(sizeof(char)*MAX_ROW_LENGTH);
            calculateDamageTotal(heroes,quests,nrOfHeroes,nrOfQuests,&damageTotal,i,names);
            strcpy(names,names+1);
            strcpy(names+strlen(names)-2,"\0");
            if(damageTotal>quests[i].damage)
            {
                fprintf(o,"%s went on to complete %s -SUCCESS (%d vs. %d) and gained %d xp.\n\n",names,quests[i].title,quests[i].damage,damageTotal,quests[i].xp);
                *totalXP+=quests[i].xp;
            }

        }
        else
        {
            if(areThereEnoughHeroes(quests,i,heroTypeVector)==0)
            {
                fprintf(o,"Cannot execute mission %s - not enough heroes of type D\n\n",quests[i].title);
            }
            if(areThereEnoughHeroes(quests,i,heroTypeVector)==1)
            {
                fprintf(o,"Cannot execute mission %s - not enough heroes of type H\n\n",quests[i].title);
            }
            if(areThereEnoughHeroes(quests,i,heroTypeVector)==2)
            {
                fprintf(o,"Cannot execute mission %s - not enough heroes of type T\n\n",quests[i].title);
            }
        }
    }
}
void ending(FILE *o, int totalXP)
{
    fprintf(o,"The group gained a total of %d XP.\n",totalXP);
    if(totalXP<REQ_EXP)
    {
        fprintf(o,"Cannot attack Argus :(");
    }
    else
    {
        fprintf(o,"ATTACKING ARGUS");
    }

}
int main()
{
    FILE *f=fopen("heroes.txt","r");
    FILE *g=fopen("quests.txt","r");
    FILE *o=fopen("outcome.txt","w");

    heroType *heroes=(heroType*)malloc(sizeof(heroType)*MAX_LINES);
    questType *quests=(questType*)malloc(sizeof(quests)*MAX_LINES);
    for(int i=0; i<MAX_LINES; i++)
    {
        defineHeroes(&heroes[i]);
        defineQuests(&quests[i]);
    }

    int nrOfHeroes=0;
    int nrOfQuests=0;
    formHeroArray(heroes,f,&nrOfHeroes);
    formQuestArray(quests,g,&nrOfQuests);
    sortHeroArray(heroes,nrOfHeroes);

    int totalXP=0;
    int* heroTypeVector=(int*)malloc(sizeof(int)*3);
    fillHeroTypeVector(heroTypeVector,heroes,nrOfHeroes);
    doQuests(heroes,quests,nrOfHeroes,nrOfQuests,heroTypeVector,&totalXP,o);
    ending(o,totalXP);

    return 0;
}
