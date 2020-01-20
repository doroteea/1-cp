#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_LENGTH 200

typedef struct
{
    char *name;
    bool *movies;
} actor;

int appearedBefore(char *name, actor *actors, int *nrOfActors)
{
    for (int i=0; i<*nrOfActors; i++)
    {
        if (strcmp(name, actors[i].name)==0)
        {
            return i;
        }
    }
    return 0;
}

void initFalse(bool *a)
{
    for (int i=0; i<MAX_LENGTH; i++)
    {
        *(a+i)=false;
    }
}

void print(actor *actors, char **movies, int nrOfActors, int nrOfMovies)
{
    for (int i=0; i<nrOfActors; i++)
    {
        printf("Actor %s starred in: ", actors[i].name);
        for (int j=0; j<=nrOfMovies; j++)
        {
            if (actors[i].movies[j])
            {
                printf("%s ", movies[j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}


void parseString(char* strbuf, actor *actors, int *nrOfActors, int nrOfMovies, char **movies)
{
    char *aux = (char*)malloc(sizeof(char)*MAX_LENGTH);
    movies[nrOfMovies] = (char*)malloc(sizeof(char)*MAX_LENGTH);

    char *p;
    p=strtok(strbuf, ",\n");
    strcpy(movies[nrOfMovies], p);

    p=strtok(NULL, ",\n");
    while (p)
    {
        strcpy(aux, p);
        int pos = appearedBefore(aux, actors, nrOfActors);
        if(!pos)
        {
            actors[*nrOfActors].name = (char*)malloc(sizeof(char)*MAX_LENGTH);
            actors[*nrOfActors].movies = (bool*)malloc(sizeof(bool)*MAX_LENGTH);
            initFalse(actors[*nrOfActors].movies);

            strcpy(actors[*nrOfActors].name, aux);
            actors[*nrOfActors].movies[nrOfMovies]=true;

            (*nrOfActors)++;
        }
        else
        {
            actors[pos].movies[nrOfMovies] = true;
        }

        p=strtok(NULL, ",\n");
    }

}

bool isFriend(actor *actors, int a, int b, int nrOfMovies)
{
    for (int i=1; i<=nrOfMovies; i++)
    {
        if (actors[a].movies[i] && actors[b].movies[i])
        {
            return 1;
        }
    }
    return 0;
}

void printFriends(actor *actors, int nrOfActors, int nrOfMovies)
{
    for (int i=0; i<nrOfActors; i++)
    {
        printf("Actor %s is friends with: ", actors[i].name);
        for (int j=0; j<nrOfActors; j++)
        {
            if (i!=j)
            {
                if (isFriend(actors, i, j, nrOfMovies))
                {
                    printf("%s ", actors[j].name);
                }
            }
        }

        printf("\n");
    }

    printf("\n");
}

char *maximumFirends (actor *actors, int nrOfActors, int nrOfMovies)
{
    int Max=0;
    char *mostFriendly = (char*)malloc(sizeof(char)*MAX_LENGTH);


    for (int i=0; i<nrOfActors; i++)
    {
        int nr=0;
        for (int j=0; j<nrOfActors; j++)
        {
            if (i!=j)
            {
                if (isFriend(actors, i, j, nrOfMovies))
                {
                    nr++;
                }
            }
        }

        if (nr>Max)
        {
            Max=nr;
            strcpy(mostFriendly, actors[i].name);
        }
    }

    return mostFriendly;
}

int main()
{
    FILE *f = fopen("movies.txt", "r");

    char *strbuf = (char*)malloc(sizeof(char)*MAX_LENGTH);
    actor *actors = (actor*)malloc(sizeof(actor)*MAX_LENGTH);
    char **movies = (char**)malloc(sizeof(char*)*MAX_LENGTH);

    int nrOfActors=0;
    int nrOfMovies=0;

    while(fgets(strbuf, MAX_LENGTH, f)!=NULL)
    {
        nrOfMovies++;
        parseString(strbuf, actors, &nrOfActors, nrOfMovies, movies);
    }

    print(actors, movies, nrOfActors, nrOfMovies);
    printFriends(actors, nrOfActors, nrOfMovies);
    printf("The person with the most friends is: %s", maximumFirends(actors, nrOfActors, nrOfMovies));

    return 0;
}
