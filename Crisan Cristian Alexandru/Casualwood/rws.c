#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
typedef struct
{
    char *name;
    char **friends;
    int nrOfFriends;
} actor;
typedef struct
{
    char *name;
    char **cast;
    int CastSize;
} movie;
bool isUnique(actor *actors,int nrOfDActors,char *wantedActorName)
{
    for(int i=0; i<nrOfDActors; i++)
    {
        if(strcmp(actors[i].name,wantedActorName)==0)
        {
            return false;
        }
    }
    return true;
}
void rasFILE(FILE *f,movie *movies,actor *actors,int *nrOfDactors,int *nrOfDMovies)
{
    *nrOfDactors=0;
    *nrOfDMovies=0;
    char *currentLine=(char*)malloc(sizeof(char)*200);
    while((currentLine=fgets(currentLine,200,f))!=NULL)
    {
        printf("da");
        movies[*nrOfDMovies].CastSize=0;
        char *info=strtok(currentLine,",");
        printf("da2");
        strcpy(movies[*nrOfDMovies].name,info);
        printf("da3");
        info=strtok(NULL,",");
        printf("da4");
        while(info!=NULL)
        {
            strcpy(movies[*nrOfDMovies].cast[movies[*nrOfDMovies].CastSize++],info);
            printf("da5");
            if(isUnique(actors,*nrOfDactors,info)==true)
            {
                strcpy(actors[*nrOfDactors].name,info);
               // (*nrOfDactors)++;
                printf("da6");
            }
            info=strtok(NULL,",");
        }

        (*nrOfDMovies)++;
    }
          printf("da");
}
void printMoviesandActors(movie *movies,actor *actors,int nrOfDmovies,int nrOfDactors)
{
    for(int i=0;i<nrOfDactors;i++)
    {
        printf("%s\nCasting:\n",movies[i].name);
        for(int j=0;j<movies[i].CastSize;j++)
        {
            printf("%s ",movies[i].cast[j]);
        }
    }
}
