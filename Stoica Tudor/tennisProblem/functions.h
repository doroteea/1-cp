#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NR_MATCHES 105
#define MAX_LENGTH_MATCH 1005
#define MAX_NR_GAMES_PLAYER 105

int nrMatches;

char **initMatches(char **s);
char **readInput(char **s,FILE *f);
void solveTask(char **s,FILE *f);
char **initOutput(char **out);
void processMatch(char *s,FILE *f);
char *buildCharArray(char *s,int a, int b);
