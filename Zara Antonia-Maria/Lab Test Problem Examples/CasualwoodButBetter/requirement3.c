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

void searchForFriendsFor(int nrMovies, int currNr, int currMovie, int currActor, movieType *movies, friendsType *actorF)
{
    int i;

    strcpy(actorF[currNr].name,movies[currMovie].actors[currActor]);

    actorF[currNr].nrFriends = 0;

    for(i=0; i<nrMovies; i++)
    {

        int j,placeInMovie = -1;
        for(j=0; j<movies[i].nrActors; j++)
        {
            ///prostie e combatarea newline-ului invizibil de la ultimul actor de pe fiecare rand
            ///pe care mi-l citeste fgets si pe care a durat 2 zile sa il vad

            int prostie = strlen(movies[i].actors[j]);
            if(movies[i].actors[j][prostie-1] < 'a' || movies[i].actors[j][prostie-1] > 'z')
            {
                movies[i].actors[j][prostie-1] = '\0';
            }

            if(strcmp(movies[i].actors[j],actorF[currNr].name) == 0)
            {
                placeInMovie = j;
            }
        }

        if(placeInMovie != -1) ///he is in movie
        {
            for(j=0; j<movies[i].nrActors; j++)
            {
                strcpy(actorF[currNr].friendArray[actorF[currNr].nrFriends],movies[i].actors[j+1]);
                actorF[currNr].nrFriends++;

            }
            actorF[currNr].nrFriends--;
        }
    }

}

int searchForFriendsForEverybody(int nrMovies, movieType *movies, friendsType *actorF)
{
    int i,total = 0;

    for(i=0; i<nrMovies; i++)
    {
        int j;
        for(j=0; j<movies[i].nrActors; j++)
        {
            int ii,isAlready = 0;

            for(ii=0; ii<total; ii++)   ///daca i-a numarat deja nu mai numara odata
            {
                if(strcmp(movies[i].actors[j],actorF[ii].name) == 0)
                {
                    isAlready = 1;
                }
            }

            if(isAlready == 0)
            {
                searchForFriendsFor(nrMovies,total,i,j,movies,actorF);
                total++;
            }
        }
    }

    return total;
}

void findWhoWasTheMostFriends(int totalActors, friendsType *actorF)
{
    int i, max=0;

    for(i=0; i<totalActors; i++)
    {
        if(actorF[i].nrFriends > max)
        {
            max = actorF[i].nrFriends;
        }
    }

    ///i, an intellectual, decided to check if there are more people with the same nr of friends

    printf("\nThe people with the most friends are:\n\n");

    for(i=0; i<totalActors; i++)
    {
        if(actorF[i].nrFriends == max)
        {
            printf("\t\t%s\n",actorF[i].name);
        }
    }

    printf("\nbecause they have %d friends.\n\nDONE.",max);
}
