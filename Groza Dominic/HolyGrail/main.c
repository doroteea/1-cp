#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EXPLORERS 10
#define MAX_LENGTH 255


typedef struct {
    char *explorerName;
    char *explorerCountry;
    int nrOfDiscoveries;
    int distanceHG;
} Explorers;

void initializeExplorers(Explorers *expl) {
    expl->explorerName = (char *) malloc(sizeof(char) * MAX_NAME);
    expl->explorerCountry = (char *) malloc(sizeof(char) * MAX_NAME);
}

/*int charToInt(char *p) {
    int length;
    length = strlen(p);
    int nr = 0;
    for (int i = 0; i < length; i++) {
        int digit;
        digit = p[i] - '0';
        nr = nr * 10 + digit;
    }
    return nr;
}

void delchar(char *x, int a, int b) {
    if ((a + b - 1) <= strlen(x)) {
        strcpy(&x[b - 1], &x[a + b - 1]);
        puts(x);
    }
}

void printExplorers(Explorers *explorer, int N) {
    for (int i = 0; i < N; i++) {
        printf("%s %s %d %d\n", explorer[i].explorerName, explorer[i].explorerCountry, explorer[i].nrOfDiscoveries,
               explorer[i].distanceHG);
    }
}
*/
void printExplorersFILE(Explorers *explorer, int N, FILE *f) {
    for (int i = 0; i < N; i++) {
        fprintf(f, "%s %s %d %d\n", explorer[i].explorerName, explorer[i].explorerCountry, explorer[i].nrOfDiscoveries,
                explorer[i].distanceHG);
    }
}

void fillStruct(Explorers *explorer, int N, FILE *f) {
    char *strbuf = (char *) malloc(sizeof(char) * MAX_LENGTH);
    for (int count = 0; count < N; count++) {
        char *tok = (char *) malloc(sizeof(char) * MAX_LENGTH);
        fgets(strbuf, MAX_LENGTH, f);
        printf("%s", strbuf);
        tok = strtok(strbuf, ",");
        strcpy(explorer[count].explorerName, tok);
        tok = strtok(NULL, ",\n");
        strcpy(explorer[count].explorerCountry, tok);
        tok = strtok(NULL, ",\n");
        explorer[count].nrOfDiscoveries = 0;
        explorer[count].distanceHG = 0;
        for (int i = 0; i < strlen(tok); i++) {
            explorer[count].nrOfDiscoveries = explorer[count].nrOfDiscoveries * 10 + (tok[i] - '0');
        }
        tok = strtok(NULL, ",\n");
        for (int i = 0; i < strlen(tok); i++) {
            explorer[count].distanceHG = explorer[count].distanceHG * 10 + (tok[i] - '0');
        }
    }
}

void sortBasedOnDiscoveries(Explorers *explorer, int m) {
    Explorers exploreraux;
    for (int i = 0; i < MAX_EXPLORERS - 1; i++) {
        for (int j = i + 1; j < MAX_EXPLORERS; j++) {
            if (explorer[j].nrOfDiscoveries > explorer[i].nrOfDiscoveries) {
                exploreraux = explorer[j];
                explorer[j] = explorer[i];
                explorer[i] = exploreraux;

            }
        }

    }

}

void sortBasedOnDistanceHG(Explorers *explorer, int N) {
    Explorers exploreraux;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (explorer[j].distanceHG < explorer[i].distanceHG) {
                exploreraux = explorer[i];
                explorer[i] = explorer[j];
                explorer[j] = exploreraux;

            }
        }

    }


}

void getGrailData(FILE *grail, int *holyGrailAge, char *GrailLoc) {
    char *strbuf = (char *) malloc(sizeof(char) * MAX_LENGTH);
    char *tok;
    fgets(strbuf, MAX_LENGTH, grail);
    tok = strtok(strbuf, ",");
    strcpy(GrailLoc, tok);
    tok = strtok(NULL, "\n");
    for (int i = 0; i < strlen(tok); i++) {
        *holyGrailAge = *holyGrailAge * 10 + (tok[i] - '0');
    }
}

int main() {
    int N, m, holyGrailAge = 0;
    FILE *f = fopen("explorers.txt", "r");
    FILE *discoveries = fopen("discoveriesExplorers.dat.txt", "w");
    FILE *grail = fopen("holyGrail.dat.txt", "r");
    FILE *grailExpl = fopen("grailExplorers.dat.txt", "w");
    Explorers *explorer = (Explorers *) malloc(sizeof(Explorers) * MAX_EXPLORERS);
    fscanf(f, "%d\n", &N);
    for (int i = 0; i < N; i++) {
        initializeExplorers(&explorer[i]);
    }
    fillStruct(explorer, N, f);
    printf("enter m:\n");
    scanf("%d", &m);
    if (m > N) {
        m = N;
    }
    sortBasedOnDiscoveries(explorer, m);
    printExplorersFILE(explorer, m, discoveries);
    char *GrailLoc = (char *) malloc(sizeof(char) * MAX_LENGTH);
    getGrailData(grail, &holyGrailAge, GrailLoc);
    printf("\n The location of the Grail is : %s and it's age is : %d\n", GrailLoc, holyGrailAge);
    sortBasedOnDistanceHG(explorer, N);
    printExplorersFILE(explorer, N, grailExpl);
    return 0;
}
