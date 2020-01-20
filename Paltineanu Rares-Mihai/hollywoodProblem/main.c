#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int length = 250;

typedef struct {

    char *actor;
    int *allTheMovies;

} problem;

void initialize(problem *v) {

    for(int i = 0; i < 100; i++) {

        v[i].actor = (char *)malloc(length);
        v[i].allTheMovies = (int *)malloc(sizeof(int) * length);
        memset(v[i].allTheMovies, 0, sizeof(int) * length);

    }
}

void initializeMovies(char **mat) {

    for(int i = 0; i < 100; i++) {

        mat[i] = (char *)malloc(150);

    }
}

int alreadyExist(char *actorA, problem *v, int numberActor) {

    for(int i = 0; i < numberActor; i++) {

        if(strcmp(actorA, v[i].actor) == 0) {

            return i;

        }
    }
    return -1;
}

void takeAllActors(char **movie, problem *v, int *numberMovie, int *numberActor, char *moviesAndActors) {

    char *tok = (char *)malloc(length);

    tok = strtok(moviesAndActors, ",\n");
    strcpy(movie[*numberMovie], tok);
    tok = strtok(NULL, ",\n");

    while(tok != NULL) {

        if(alreadyExist(tok, v, *numberActor) != -1) {

            v[alreadyExist(tok, v, *numberActor)].allTheMovies[*numberMovie] = 1;
            tok = strtok(NULL, ",\n");

        } else {

            strcpy(v[*numberActor].actor, tok);
            v[*numberActor].allTheMovies[*numberMovie] = 1;
            (*numberActor)++;
            tok = strtok(NULL, ",\n");

        }
    }
    (*numberMovie)++;
}

void showingMoviesAndActors(char **movie, problem *v, int numberMovie, int numberActors) {

    for(int i = 0; i < numberMovie; i++) {

        printf("In the movie '%s' played the following actors:", movie[i]);
        for(int j = 0; j < numberActors; j++) {

            if(v[j].allTheMovies[i] == 1)   {

                printf(" %s", v[j].actor);

            }
        }
        printf("\n");
    }
}

void findingFriends(problem *v, int numberActors, int numberMovies, int *maxFriends) {

    for(int i = 0; i < numberActors; i++) {

        printf("Friends of %s:", v[i].actor);

        for(int j = 0; j < numberActors; j++) {

            if(j != i) {

                for(int k = 0; k < numberMovies; k++) {

                    if(v[i].allTheMovies[k] * v[j].allTheMovies[k]) {

                        printf(" %s", v[j].actor);
                        k = numberMovies;
                        maxFriends[i]++;

                    }
                }
            }
        }
        printf("\n");
    }
}

int takeMaxFriends(int *maxFriends, int nrActors) {

    int maxim = -1;
    int pos = 0;

    for(int i = 0; i < nrActors; i++) {

        if(maxFriends[i] > maxim) {

            maxim = maxFriends[i];
            pos = i;

        }
    }

    return pos;
}

void printingMaxFriends(problem *v, int pos) {

    printf("The person with the most number of friends is: %s", v[pos].actor);

}

int main() {

    FILE *f;
    f = fopen("movies.txt", "r");

    if(f == NULL) {
        return -1;
    }

    char *moviesAndActors = (char *)malloc(length);
    char **movie = (char **)malloc(sizeof(char *) * 100);
    int movieNr = 0;
    int actorNr = 0;
    int *maxFriends = (int *)malloc(sizeof(int) * length);
    memset(maxFriends, 0, sizeof(int) * length);

    problem *vect = (problem *)malloc(sizeof(problem) * length);

    initialize(vect);
    initializeMovies(movie);

    while(fgets(moviesAndActors, 250, f) != NULL) {

        takeAllActors(movie, vect, &movieNr, &actorNr, moviesAndActors);

    }

    showingMoviesAndActors(movie, vect, movieNr, actorNr);

    findingFriends(vect, actorNr, movieNr, maxFriends);

    printingMaxFriends(vect, takeMaxFriends(maxFriends, actorNr));
    return 0;
}
