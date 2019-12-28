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
        movies[*nrOfDMovies].CastSize=0;
        char *info=strtok(currentLine,",");
        movies[*nrOfDMovies].name=(char*)malloc(sizeof(char)*30);
        strcpy(movies[*nrOfDMovies].name,info);
        info=strtok(NULL,",");
        movies[*nrOfDMovies].cast=(char**)malloc(sizeof(char*)*20);
        while(info!=NULL)
        {
            movies[*nrOfDMovies].cast[movies[*nrOfDMovies].CastSize]=(char*)malloc(sizeof(char)*20);
            strcpy(movies[*nrOfDMovies].cast[movies[*nrOfDMovies].CastSize++],info);
            if((int)info[strlen(info)-1]==10)
            {
                info[strlen(info)-1]='\0';
            }
            if(isUnique(actors,*nrOfDactors,info)==true)
            {

                actors[*nrOfDactors].name=(char*)malloc(sizeof(char)*30);
                strcpy(actors[*nrOfDactors].name,info);
                (*nrOfDactors)++;
            }
            info=strtok(NULL,",");
        }

        (*nrOfDMovies)++;
    }

}
void printMoviesandActors(movie *movies,actor *actors,int nrOfDmovies,int nrOfDactors)
{
    for(int i=0; i<nrOfDmovies; i++)
    {
        printf("%s\nCasting:\n",movies[i].name);
        for(int j=0; j<movies[i].CastSize; j++)
        {
            printf("%s ",movies[i].cast[j]);
        }
    }
}
bool isCasting(movie film,char *actorName)
{
    for(int i=0; i<film.CastSize; i++)
    {
        if(strcmp(actorName,film.cast[i])==0)
        {
            return true;
        }
    }
    return false;
}
bool bro_checkIFunique(actor player,char *broName)
{
    for(int i=0; i<player.nrOfFriends; i++)
    {
        if(strcmp(player.friends[i],broName)==0)
        {
            return false;
        }
    }
    return true;
}
void addFriend(actor *player,char *friendName)
{
    strcpy((*player).friends[(*player).nrOfFriends],friendName);
    (*player).nrOfFriends++;
}
void memorise_OnesBros_FromAllMovies(movie *movies,actor *one,int nrOfMovies)
{
    for(int i=0; i<nrOfMovies; i++)
    {
        if(isCasting(movies[i],(*one).name)==true)
        {
            for(int j=0; j<movies[i].CastSize; j++)
            {
                if(bro_checkIFunique((*one),movies[i].cast[j])==true&&strcmp(movies[i].cast[j],(*one).name)!=0)
                {
                    (*one).friends[(*one).nrOfFriends]=(char*)malloc(sizeof(char)*30);
                    addFriend(one,movies[i].cast[j]);
                }
            }
        }
    }
}
void detFriendsOftheActors(movie *movies,actor *actors,int nrOfDmovies,int nrOfDactors)
{
    for(int i=0; i<nrOfDactors; i++)
    {
        actors[i].friends=(char**)malloc(sizeof(char*)*150);
        memorise_OnesBros_FromAllMovies(movies,&actors[i],nrOfDmovies);
    }
}
int PosofActor(char *name,actor *actors,int nrOfActors)
{
    for(int i=0; i<nrOfActors; i++)
    {
        if(strcmp(name,actors[i].name)==0)
        {
            return i;
        }
    }
    return -1;
}
void showOnesAllFriends(actor one)
{

    printf("The friends of %s are:\n",one.name);
    for(int i=0; i<one.nrOfFriends; i++)
    {
        printf("%s_da\n",one.friends[i]);
    }
}
