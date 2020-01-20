#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    FILE *list;
    list = fopen("movies.txt","r");

    movieType *movies = (movieType*)malloc(sizeof(movieType)*10);

    ///Requirement 1

    int nrMovies;

    initialize(movies);

    nrMovies = putInStructure(list,movies);

    printStructures(nrMovies,movies);

    ///Requirement 2

    char *name = (char*)malloc(sizeof(char)*25);
    printf("Input name of the actor wanted: ");
    gets(name);

    friendsType *actorF = (friendsType*)malloc(sizeof(friendsType)*25); ///nu avem mai mult de 25 actori

    initializeF(actorF);

    searchForFriendsRequest(name,nrMovies,movies,actorF);

    printFriends(actorF);

    ///Requirement 3

    int totalActors;

    totalActors = searchForFriendsForEverybody(nrMovies,movies,actorF);

    findWhoWasTheMostFriends(totalActors,actorF);

    return 0;
}
