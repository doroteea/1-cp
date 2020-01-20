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


///Requirement 1

void initialize(movieType *movies);
int putInStructure(FILE *list, movieType *movies);
void printStructures(int nrMovies, movieType *movies);

///Reguirement 2

void initializeF(friendsType *actorF);
void searchForFriendsRequest(char *name, int nrMovies, movieType *movies, friendsType *actorF);
void printFriends(friendsType *actorF);

///Requirement 3

void searchForFriendsFor(int nrMovies, int currNr, int currMovie, int currActor, movieType *movies, friendsType *actorF);
int searchForFriendsForEverybody(int nrMovies, movieType *movies, friendsType *actorF);
void findWhoWasTheMostFriends(int totalActors, friendsType *actorF);

