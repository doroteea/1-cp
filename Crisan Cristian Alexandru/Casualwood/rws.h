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
void rasFILE(FILE *f,movie *movies,actor *actors,int *nrOfDactors,int *nrOfDMovies);
void printMoviesandActors(movie *movies,actor *actors,int nrOfDmovies,int nrOfDactors);
void detFriendsOftheActors(movie *movies,actor *actors,int nrOfDmovies,int nrOfDactors);
void showOnesAllFriends(actor one);
int PosofActor(char *name,actor *actors,int nrOfActors);

