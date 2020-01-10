/*
 * They say in Hollywood, every actor knows every other actor. In Casualwood however, this affirmation does not hold
 * true. In Casualwood, every actor knows another actor if and only if they once starred in a movie together.
 * In movies.txt you are given a list of movies and their cast (see format below).
 *
 * Requirement 1: read all the movies from the file and store them in appropriate structures printing everything out
 * of the console.
 * Requirement 2: by reading an actor name from the keyboard, print out all the friends of that actor (i.e. all the cast
 * members of the movies he's been in).
 * Requirement 3: extract the person with the most friends.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxNrOfMovies = 20;
const int maxLengthOfString = 100;

typedef struct {
    char *title;
    char **cast;
    int actorCount;
} movieType;

void initializeMovie(movieType *mov) {
    mov->title = (char *) malloc(sizeof(char) * 30);
    mov->cast = (char **) malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++) {
        mov->cast[i] = (char *) malloc(sizeof(char) * 30);
    }
}

int readMovies(FILE *f, movieType *movie) {
    int nrOfMovies = 0;
    char *buffer = (char *) malloc(sizeof(char) * maxLengthOfString);
    while (fgets(buffer, maxLengthOfString, f) != NULL) {
        movie[nrOfMovies].actorCount = 0;
        char *pch;
        pch = strtok(buffer, ",");
        strcpy(movie[nrOfMovies].title, pch);
        pch = strtok(NULL, ",");
        while (pch != NULL) {
            strcpy(movie[nrOfMovies].cast[movie[nrOfMovies].actorCount], pch);
            movie[nrOfMovies].actorCount++;
            pch = strtok(NULL, ",");
        }
        nrOfMovies++;
    }

    return nrOfMovies;

}

void printMovie(movieType movie) {
    printf("Movie title: %s; ", movie.title);
    printf("Actors in the movie: ");
    for (int j = 0; j < movie.actorCount - 1; j++) {
        printf("%s,", movie.cast[j]);
    }
    printf("%s", movie.cast[movie.actorCount - 1]);
}

int isActor(movieType movie, char *actorName) {
    int ok = 0;
    for (int i = 0; i < movie.actorCount && ok == 0; i++) {
        if (strcmp(actorName, movie.cast[i]) == 0)
            ok = 1;
    }

    return ok;
}

void printActors(movieType movie, char *actorName) {
    if (isActor(movie,actorName)==1)
    {
        for (int i=0;i<movie.actorCount;i++)
        {
            if(strcmp(movie.cast[i],actorName)!=0)
            {
                printf("%s\n",movie.cast[i]);
            }
        }
    }
}

int friendCount (movieType *movie, int nrOfMovies, char *actorName)
{
    int friends=0;
    for (int i=0;i<nrOfMovies;i++)
    {
        if (isActor(movie[i],actorName)==1)
        {
            friends=friends+movie[i].actorCount-1;
        }
    }

    return friends;
}

char *actorWithMostFriends(movieType *movie, int nrOfMovies)
{
    int maxFriends=0;
    char *actorWithMostFriends=(char*)malloc(sizeof(char)*maxLengthOfString);
    for (int i=0;i<nrOfMovies;i++)
    {
        for (int j=0;j<movie[i].actorCount;i++)
        {
            int nrOfFriends=friendCount(movie,nrOfMovies,movie[i].cast[j]);
            if (nrOfFriends>maxFriends)
            {
                maxFriends=nrOfFriends;
                strcpy(actorWithMostFriends,movie[i].cast[j]);
            }
        }
    }

    return actorWithMostFriends;

}

int main() {

    FILE *f;
    f = fopen("movies.txt", "r");

    movieType *movie = (movieType *) malloc(sizeof(movieType) * maxNrOfMovies);
    for (int i = 0; i < maxNrOfMovies; i++) {
        initializeMovie(&movie[i]);
    }

    int nrOfMovies = readMovies(f, movie);

    for (int i = 0; i < nrOfMovies; i++) {
        printMovie(movie[i]);
    }

    printf("\n\n");

    char *actorName = (char *) malloc(sizeof(char) * maxLengthOfString);
    printf("Please type an actor name: ");
    gets(actorName);

    printf("The friends of actor %s are:\n",actorName);
    for (int i = 0; i < nrOfMovies; i++) {
        printActors(movie[i], actorName);
    }

    char *actor=actorWithMostFriends(movie,nrOfMovies);
    printf("The actor with the most friends is: %s", actor);

    fclose(f);

    return 0;
}