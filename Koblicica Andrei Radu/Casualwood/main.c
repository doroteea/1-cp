#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROW_LENGTH 200
#define MAX_NAME_LENGTH 30
#define MAX_MOVIES 10
#define MAX_ACTORS_IN_MOVIE 10
typedef struct
{
    char *title;
    char **cast;
    int actorCount;
} movieType;
void initializeMovie(movieType *mov)
{
    mov->title=(char*)malloc(sizeof(char)*MAX_NAME_LENGTH);
    mov->cast=(char**)malloc(sizeof(char*)*MAX_ACTORS_IN_MOVIE);
    for(int i=0; i<MAX_ACTORS_IN_MOVIE; i++)
    {
        mov->cast[i]=(char*)malloc(sizeof(char)*MAX_NAME_LENGTH);
    }
}
void displayMovies(movieType *movies,int movieCount)
{
    for(int i=0; i<movieCount; i++)
    {
        printf("Title of movie %d: %s\nCast of movie %d:\n",i,movies[i].title,i);
        for(int j=0; j<=movies[i].actorCount; j++)
        {
            printf("%s\n",movies[i].cast[j]);
        }
    }
}
int isActorInMovie(char *actorName, movieType *movies, int movieCount, int i)
{
    int ok=0;
    for(int j=0; j<movies[i].actorCount && ok==0; j++)
    {
        if(strcmp(actorName,movies[i].cast[j])==0)
            ok=1;
    }
    return ok;
}
void displayFriends(char *actorName, movieType *movies, int movieCount)
{
    printf("The friends of %s are:\n",actorName);
    for(int i=0; i<movieCount; i++)
    {
        if(isActorInMovie(actorName,movies,movieCount,i)!=0)
        {
            for(int j=0; j<movies[i].actorCount; j++)
            {
                if(strcmp(movies[i].cast[j],actorName)!=0)
                {
                    printf("%s\n",movies[i].cast[j]);
                }
            }
        }
    }
}
void findMaxFriends(movieType *movies,int *maxFriends, char *maxName,char *actorName, int movieCount)
{
    int nrOfFriends;
    for(int i=0; i<movieCount; i++)
    {
        for(int j=0; j<movies[i].actorCount; j++)
        {
            strcpy(actorName,movies[i].cast[j]);
            nrOfFriends=0;
            for(int k=0; k<movieCount; k++)
            {
                if(isActorInMovie(actorName,movies,movieCount,k)!=0)
                {
                    nrOfFriends+=movies[k].actorCount-1;
                }
            }
            if(nrOfFriends>*maxFriends)
                    {
                        *maxFriends=nrOfFriends;
                        strcpy(maxName,actorName);
                    }
        }
    }
}
int main()
{
    FILE *f=fopen("movies.txt","r");
    char * strbuf = (char*) malloc(sizeof(char)*MAX_ROW_LENGTH);
    movieType *movies=(movieType*)malloc(sizeof(movieType)*MAX_MOVIES);
    for(int i=0; i<MAX_MOVIES; i++)
    {
        initializeMovie(&movies[i]);
    }
    int movieCount=0;
    while(fgets(strbuf,MAX_ROW_LENGTH,f)!=NULL)
    {
        movies[movieCount].actorCount=0;
        char *p;
        p=strtok(strbuf,",\n");
        strcpy(movies[movieCount].title,p);
        p=strtok(NULL,",\n");
        while(p)
        {
            strcpy(movies[movieCount].cast[movies[movieCount].actorCount],p);
            movies[movieCount].actorCount++;
            p=strtok(NULL,",\n");
        }
        movieCount++;
    }
    displayMovies(movies,movieCount);

    char *actorName=(char*)malloc(sizeof(char)*MAX_NAME_LENGTH);
    int maxFriends=0;
    char *maxName=(char*)malloc(sizeof(char)*MAX_NAME_LENGTH);

    printf("Please input actor name:");
    gets(actorName);
    displayFriends(actorName,movies,movieCount);
    findMaxFriends(movies,&maxFriends,maxName,actorName,movieCount);
    printf("\nActor %s has the most friends. He has %d friends\n",maxName,maxFriends);
    return 0;
}
