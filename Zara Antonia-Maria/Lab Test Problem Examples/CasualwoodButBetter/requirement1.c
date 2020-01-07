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

void initialize(movieType *movies)
{

    int i;
    for(i=0; i<10; i++)
    {
        movies[i].title = (char*)malloc(sizeof(char)*25);
    }

    for(i=0; i<10; i++)
    {
        movies[i].actors = (char**)malloc(sizeof(char*)*10);
        ///max 10 actors in a movie

        int j;
        for(j=0; j<10; j++)
        {
            movies[i].actors[j] = (char*)malloc(sizeof(char)*25);
            ///max 25 letters per actor name
        }
    }
}

int putInStructure(FILE *list, movieType *movies)
{
    char *strbuf = (char*)malloc(sizeof(char)*200); ///sper

    int i = 0;
    while(fgets(strbuf,200,list)!=NULL)
    {
        char *p = (char*)malloc(sizeof(char)*30);

        int isMovie = 1;

        for(p = strtok(strbuf,","); p ; p = strtok(NULL,","))
        {
            if(isMovie == 0)
            {
                strcpy(movies[i].actors[movies[i].nrActors],p);
                movies[i].nrActors++;
            }
            if(isMovie == 1)
            {
                movies[i].nrActors = 0;
                isMovie = 0;
                strcpy(movies[i].title,p);
            }
        }
        i++;
    }

    return i;
}

void printStructures(int nrMovies, movieType *movies)
{
    int i;
    for(i=0; i<nrMovies; i++)
    {
        printf("MOVIE %d: %s",i+1,movies[i].title);

        int j;
        for(j=0; j<movies[i].nrActors; j++)
        {
            printf("\n\t\t%s",movies[i].actors[j]);
        }
        printf("\n");
    }
}
