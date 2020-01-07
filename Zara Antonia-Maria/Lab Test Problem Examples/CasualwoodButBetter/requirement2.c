#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *title;
    char **actors;
    int nrActors;
} movieType;

typedef struct
{
    char *name;
    int nrFriends;
    char **friendArray;
} friendsType;

void initializeF(friendsType *actorF)
{
    int i;
    for(i=0; i<25; i++) ///avem max 25 actori
    {
        actorF[i].friendArray = (char**)malloc(sizeof(char*)*20); ///fiecare are max 20 prt

        int j;
        for(j=0; j<20; j++)
        {
            actorF[i].friendArray[j] = (char*)malloc(sizeof(char)*25); ///nume mai scurte de 25
        }
    }
    for(i=0; i<25; i++)
    {
        actorF[i].nrFriends = 0;
    }
    for(i=0; i<25; i++)
    {
        actorF[i].name = (char*)malloc(sizeof(char)*25);
    }
}

void searchForFriendsRequest(char *name, int nrMovies, movieType *movies, friendsType *actorF)
{
    int i;

    strcpy(actorF[0].name,name);

    for(i=0; i<nrMovies; i++)
    {
        int j,placeInMovie = -1;
        for(j=0; j<movies[i].nrActors; j++)
        {
            int prostie = strlen(movies[i].actors[j]);
            if(movies[i].actors[j][prostie-1] < 'a' || movies[i].actors[j][prostie-1] > 'z')
            {
                movies[i].actors[j][prostie-1] = '\0';
            }

            if(strcmp(movies[i].actors[j],actorF[0].name) == 0)
            {
                placeInMovie = j;
            }
        }

        if(placeInMovie != -1) ///he is in movie
        {
            for(j=0; j<movies[i].nrActors; j++)
            {
                if(strcmp(actorF[0].name,movies[i].actors[j]) != 0)
                {
                    strcpy(actorF[0].friendArray[actorF[0].nrFriends],movies[i].actors[j]);
                    actorF[0].nrFriends++;
                }
            }
        }
    }

    printf("\n%s has %d friends but are they really friends or merely acquintances?\n",name,actorF[0].nrFriends);
}

void printFriends(friendsType *actorF)
{
    printf("%s's friends are:\n",actorF[0].name);

    int i;
    for(i=0; i<actorF[0].nrFriends; i++)
    {
        printf("\t\t%s\n",actorF[0].friendArray[i]);
    }
}
