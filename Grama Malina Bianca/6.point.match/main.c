/*
 * A tennis match is a sequence of sets; a set is a sequence of games; a game is a sequence of points. The number of points won
 * by each player is accumulated from zero within a set; and the number of sets won by each player is accumulated from zero within a match.
 * A game is won by the first player to accumulate at least 4 points and lead by at least 2 points (games could last indefinitely).
 * A set is won by the first player to accumulate at least 6 games and lead by at least 2 sets (complete matches always consist of two or
 * three sets). The score is reported by giving the number of games each player won in each set, e.g. “6-3, 2-6, 7-5” or “6- 1, 6-1”.
 * Each line of the input is a string p describing the point winners throughout a match. Player A wins the ith point of the match if pi=’A’;
 * player B wins the ith point of the match if pi =’B’.
 * For each match, output the winner and the score of each complete set. If the input includes enough points to determine the winner of
 * the match, report which player won the match and discard the rest of the input line. If the match does not contain enough points to
 * determine the winner, output the score of the last set in progress and report that the match is incomplete.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxLengthLine = 300;
const int maxNrOfMatches = 20;

void scoreMatch(char *s, FILE *o)
{
    int pointsA=0, pointsB=0, gamesA=0, gamesB=0, setsA=0, setsB=0;
    int nrOfSets=0;
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] == 'A') {
            pointsA++;
            if (pointsA >= 4 && abs(pointsA - pointsB) >= 2) {
                pointsA = 0;
                pointsB = 0;
                gamesA++;
                if (gamesA >= 6 && abs(gamesA - gamesB) >= 2) {
                    setsA++;
                    nrOfSets++;
                    fprintf(o,"Set score: A-%d B-%d\n", gamesA,gamesB);
                    gamesA = 0;
                    gamesB = 0;
                    if ((setsA == 2 && setsB == 0) || (setsA == 2 && setsB == 1)) {
                        fprintf(o,"Match over. A wins\n");
                    }
                }
            }
        } else if (s[j] == 'B') {
            pointsB++;
            if (pointsB >= 4 && abs(pointsA - pointsB) >= 2) {
                pointsA = 0;
                pointsB = 0;
                gamesB++;
                if (gamesB >= 6 && abs(gamesA - gamesB) >= 2) {
                    setsB++;
                    nrOfSets++;
                    fprintf(o,"Set score: A-%d B-%d\n", gamesA,gamesB);
                    gamesA = 0;
                    gamesB = 0;
                    if ((setsB == 2 && setsA == 0) || (setsB == 2 && setsA == 1)) {
                        fprintf(o,"Match over. B wins\n");
                    }
                }
            }
        }
    }

    if (nrOfSets<3)
    {
        fprintf(o,"Partial set score: A-%d B-%d\n", gamesA, gamesB);
        fprintf(o,"Match incomplete\n");
    }

}

int main() {
    FILE *f;
    f = fopen("tenis.txt", "r");

    char **matrix = (char **) malloc(sizeof(char *) * maxNrOfMatches);
    for (int i = 0; i < maxNrOfMatches; i++) {
        *(matrix + i) = (char *) malloc(sizeof(char) * maxLengthLine);
    }
    char *buffer = (char *) malloc(sizeof(char) * maxLengthLine);
    int nrOfLines = 0;
    while (fgets(buffer, maxLengthLine, f) != NULL) {
        strcpy(*(matrix + nrOfLines), buffer);
        nrOfLines++;
    }

    FILE *o;
    o = fopen("output.txt", "w");

    for (int i = 0; i < nrOfLines; i++) {
        scoreMatch(matrix[i],o);
    }

    fclose(o);
    fclose(f);
    return 0;
}