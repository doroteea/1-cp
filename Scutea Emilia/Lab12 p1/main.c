#include <stdio.h>
#include <stdlib.h>

const int MAX_LENGTH = 200;

typedef struct
{

    int *nrOfMovies;
    char actor;
} movies;

void initializeMovies(movies *m)
{

    m->nrOfMovies=(int*)malloc(sizeof(int)*100);
    m->actor=(char*)malloc(sizeof(char)*100);
}
void write ()
{
    movies m[100];
    FILE * f;
    int i=0;
    f=fopen ("movie.txt","r");
    //actor *a=(char*)malloc(sizeof(char)*100);
    char * p = (char*) malloc(sizeof(char)*MAX_LENGTH);
    char *token;
    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);

    while(fgets(strbuf,MAX_LENGTH, f) != NULL)
    {

        token=strtok(f,",");
        while(token!=NULL)
        {
            strcpy(m[i].actor,token);
            i++;
            token=strtok(NULL,",");
        }

    }
}

int main()
{
    FILE * f;

    f=fopen("movie.txt","rw+");
    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);

    while(fgets(strbuf,MAX_LENGTH, f) != NULL)
        puts(strbuf);
    movies *m;
    write(f);
}
