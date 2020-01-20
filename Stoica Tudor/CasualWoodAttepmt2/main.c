#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXIMUM_DIMENSION_ROW 1005
typedef struct
{
    char *nameOfMovie;
    int nrOfActors;
    char ** actor;

} Movies;

int nrOfMovies;
int totalNrOfActors;

void readFromFile(Movies* m);
void task1(Movies* m);
void task2(Movies* m);
void task3(Movies* m);
bool notMentionedBefore(char** list,char* actor);
char **getAllActors(Movies *mov);
int getNrOfFriendsOfActor(Movies *w,char * act);

void readFromFile(Movies* m)
{
    FILE* f;
    char filename[]="movies.txt";
    char s[MAXIMUM_DIMENSION_ROW];
    f = fopen(filename, "r");

    while (fgets(s, sizeof(s), f) != NULL)
    {
        bool b=false;
        char* token=strtok(s,",");

        while(token!=NULL)
        {
            if(b==false)
            {
                strcpy(m[nrOfMovies].nameOfMovie,token);
                b=true;
            }

            else
            {
                int index=m[nrOfMovies].nrOfActors;
                strcpy(m[nrOfMovies].actor[index],token);
                m[nrOfMovies].nrOfActors++;
            }
            token=strtok(NULL,",");
        }
        nrOfMovies++;
    }
    fclose(f);
}

void task1(Movies* m)
{
    for(int i=0; i<nrOfMovies; i++)
    {
        printf("%s \n",m[i].nameOfMovie);

        for(int j=0; j<m[i].nrOfActors; j++)
        {
            printf("%s   ",m[i].actor[j]);
        }
        printf("\n \n");
    }
}

void task2(Movies* m)
{
    printf("Introduce the name of the actor \n");

    char *actorName=(char *) malloc(25);
    gets(actorName);

    int* v=(int *) calloc(105,sizeof(int)); /// I put in v the indexes of movies in which actorName appears
    int vLen=0;

    int mentionedLen=0;
    char ** mentioned=(char **) malloc(sizeof(char *)*105);
    /// the purpose of this mentioned string vector is to check whether a certain friend has been processed before
    /// if that's the case, we will not count that friend again

    for(int i=0; i<105; i++)
    {
        mentioned[i]=(char *) malloc(25);
    }

    printf("\n%s's friends: \n \n",actorName);

    for(int i=0; i<nrOfMovies; i++)
    {
        for(int j=0; j<m[i].nrOfActors; j++)
        {
            if(strcmp(actorName,m[i].actor[j])==0)
            {
                v[vLen]=i;
                vLen++;
                break;
            }
        }
    } /// I put in v the indexes of movies in which actorName appears

    for(int i=0; i<vLen; i++)
    {
        for(int j=0; j<m[v[i]].nrOfActors; j++)
        {
            if(strcmp(actorName,m[v[i]].actor[j])!=0)
            {
                bool apparition=false;

                for(int k=0; k<mentionedLen; k++)
                {
                    if(strcmp(mentioned[k],m[v[i]].actor[j])==0)
                    {
                        apparition=true;
                        break;
                    }
                }

                if(apparition==false)
                {
                    strcpy(mentioned[mentionedLen],m[v[i]].actor[j]);
                    mentionedLen++;
                    printf("%s \n",m[v[i]].actor[j]);
                }
            }
        }
    }
}

bool notMentionedBefore(char** list,char* actor)
{
    for(int i=0; i<totalNrOfActors; i++)
    {
        if(strcmp(actor,list[i])==0)
        {
            return false;
        }
    }
    return true;
}

char **getAllActors(Movies *mov)
{
    char **vec=(char **) malloc(sizeof(char *)*105);
    for(int i=0; i<105; i++)
    {
        vec[i]=(char *) malloc(25);
    }

    for(int i=0; i<nrOfMovies; i++)
    {
        for(int j=0; j<mov[i].nrOfActors-1; j++)
        {
            if(notMentionedBefore(vec,mov[i].actor[j])==true)
            {
                strcpy(vec[totalNrOfActors],mov[i].actor[j]);
                totalNrOfActors++;
            }
        }
    }
    return vec;
}

int getNrOfFriendsOfActor(Movies *w,char * act)
{
    int mentionedLen=0;
    int* v=(int *) calloc(105,sizeof(int)); /// I put in v the indexes of movies in which act appears
    int vLen=0;
    int cnt=0;

    char ** mentioned=(char **) malloc(sizeof(char *)*105);
    /// the purpose of this mentioned string vector is to check whether a certain friend has been processed before
    /// if that's the case, we will not count that friend again

    for(int i=0; i<105; i++)
    {
        mentioned[i]=(char *) malloc(25);
    }

    for(int i=0; i<nrOfMovies; i++)
    {
        for(int j=0; j<w[i].nrOfActors; j++)
        {
            if(strcmp(act,w[i].actor[j])==0)
            {
                v[vLen]=i;
                vLen++;
                break;
            }
        }
    } /// I put in v the indexes of movies in which act appears

    for(int i=0; i<vLen; i++)
    {
        for(int j=0; j<w[v[i]].nrOfActors; j++)
        {
            if(strcmp(act,w[v[i]].actor[j])!=0)
            {
                bool apparition=false;

                for(int k=0; k<mentionedLen; k++)
                {
                    if(strcmp(mentioned[k],w[v[i]].actor[j])==0)
                    {
                        apparition=true;
                        break;
                    }
                }

                if(!apparition)
                {
                    strcpy(mentioned[mentionedLen],w[v[i]].actor[j]);
                    mentionedLen++;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void task3(Movies* m)
{
    int cnt=0,maxi=-1;
    char** v=getAllActors(m);

    int nrOfWinners=0;
    char ** winner=(char **) malloc(105*sizeof(char *));
    for(int i=0; i<105; i++)
    {
        winner[i]=(char *) malloc(25);
    } /// winner is the string vector in which I put actors with the highest nr of friends

    for(int q=0; q<totalNrOfActors; q++)
    {
        cnt=getNrOfFriendsOfActor(m,v[q]);

        if(cnt==maxi)
        {
            strcpy(winner[nrOfWinners],v[q]);
            nrOfWinners++;
        }

        else if(cnt>maxi && cnt!=0)
        {
            maxi=cnt;
            strcpy(winner[0],v[q]);
            nrOfWinners=1;
        }
    }

    printf("Actors with the biggest number of friends (%d) \n",maxi-1);

    for(int i=0; i<nrOfWinners; i++)
    {
        printf("%s \n",winner[i]);
    }

// printf("%s \n",winner[0]);
}

int main()
{
    Movies * obj =(Movies *) malloc(sizeof(Movies)*105);

    for(int i=0; i<105; i++)
    {
        obj[i].nameOfMovie=(char *) malloc(105);
        obj[i].actor=(char **) malloc(sizeof(char *)*105);

        for(int j=0; j<105; j++)
        {
            obj[i].actor[j]=(char *) malloc(25);
            obj[i].nrOfActors=0;
        }
    }

    readFromFile(obj);

    printf("Task 1: \n****************** \n");
    task1(obj);
    printf("End of Task 1: \n****************** \n");

    printf("Task 2: \n****************** \n");
    task2(obj);
    printf("End of Task 2: \n****************** \n");

    printf("Task 3: \n****************** \n");
    task3(obj);
    printf("End of Task 3: \n****************** \n");

    return 0;
}
