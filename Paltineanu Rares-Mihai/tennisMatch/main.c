/**
A tennis match is a sequence of sets; a set is a sequence of games; a game is a sequence of points.
The number of points won by each player is accumulated from zero within a set;
and the number of sets won by each player is accumulated from zero within a match.
A game is won by the first player to accumulate at least 4 points and lead by at least 2 points (games could last indefinitely).
A set is won by the first player to accumulate at least 6 games and lead by at least 2 sets (complete matches always consist of two or three sets).
The score is reported by giving the number of games each player won in each set,
e.g. “6-3, 2-6, 7-5” or “61, 6-1”. Each line of the input is a string p describing the point winners throughout a match.
Player A wins the ith point of the match if pi=’A’; player B wins the ith point of the match if pi =’B’.
For each match, output the winner and the score of each complete set. If the input includes enough points to determine the winner of the match,
report which player won the match and discard the rest of the input line. If the match does not contain enough points to determine the winner,
output the score of the last set in progress and report that the match is incomplete
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printingSet(int gamesA, int gamesB, FILE* out) {

    fprintf(out, "Set score: A-%d B-%d\n", gamesA, gamesB);

}

void printingWinner(char winner, FILE* out) {

    fprintf(out, "\n%c is the winner!", winner);

}

void printingPartial(int gamesA, int gamesB, FILE* out) {

    fprintf(out, "Partial set score: A-%d B-%d\n", gamesA, gamesB);

}

void determingTheWinner(char* matches, FILE* out) {

    int size = strlen(matches);

    int pointsA = 0, pointsB = 0;

    int gamesA = 0, gamesB = 0;

    int setA = 0, setB = 0;

    int i = 0;

    for(i = 0; i < size && (setA != 2 || setB != 2); i++) {

        if(matches[i] == 'A') {

            pointsA++;

        } else if(matches[i] == 'B') {

            pointsB++;

        }

        if(pointsA >= 4 && pointsA - pointsB >= 2) {

            gamesA++;

            pointsA = 0;
            pointsB = 0;

        }

        if(pointsB >= 4 && pointsB - pointsA >= 2) {

            gamesB++;

            pointsA = 0;
            pointsB = 0;

        }

        if(gamesA >= 6 && gamesA - gamesB >= 2) {

            setA++;

            printingSet(gamesA, gamesB, out);

            pointsA = 0;
            pointsB = 0;
            gamesA = 0;
            gamesB = 0;

        }

        if(gamesB >= 6 && gamesB - gamesA >= 2) {

            setB++;

            printingSet(gamesA, gamesB, out);

            pointsA = 0;
            pointsB = 0;
            gamesA = 0;
            gamesB = 0;

        }

    }

    if(setA == 2) {

        printingWinner('A', out);

    } else if(setB == 2) {

        printingWinner('B', out);

    } else if(setA != 2 && setB != 2) {

        printingPartial(gamesA, gamesB, out);
        fprintf(out, "Match incomplete.\n\n");

    }

}


void read(int* nrOfMatches, char* matches, FILE* in, FILE* out) {

    fscanf(in, "%d\n", nrOfMatches);

    for(int i = 0; i < (*nrOfMatches); i++) {

        fgets(matches, 10000, in);
        determingTheWinner(matches, out);
    }

}

int main() {

    char *matches = (char*)malloc(10000);

    FILE* in = fopen("tennis.in", "r");
    FILE* out = fopen("tennis.out", "w");

    if(in == NULL || out == NULL) {

        return -1;

    }

    int nrOfMatches;
    read(&nrOfMatches, matches, in, out);

    //determingTheWinner(matches, out);
    return 0;
}
