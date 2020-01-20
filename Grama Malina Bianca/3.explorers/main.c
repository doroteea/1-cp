/*
 * N explorers are being read from a file (explorers.dat) each having a name, country of origin, number of discoveries and their
 * relative distance from the Holy Grail. (See example of input)
 * The Holy Grail is a unique artefact which has a country of origin and an age, both read from a file (holyGrail.dat).
 * - Read all the explorers from the input file
 * - Sort them based on the number of discoveries and print out (in file discoveriesExplorers.dat) the
 * first m (is read from the keyboard at this step) explorers based on this number of discoveries
 * field. If m > n simply print them all out. (first explorer printed→most discoveries)
 * - Read the details of the Holy Grail artefact from the file and re-sort the explorers based on their
 * distance to the Holy Grail (first in array is closest to the Holy Grail)
 * - Print out the newly sorted array of explorers in a file called grailExplorers.dat
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxLengthOfString = 100;
const int maxNrOfExplorers = 30;

typedef struct {
    char *name;
    char *countryOfOrigin;
    int nrOfDiscoveries;
    int distFromTheHolyGrail;
} explorers;

typedef struct {
    char *countryOfOrigin;
    int age;
}holyGrail;

void initializeExplorers(explorers *ex) {
    ex->name = (char *) malloc(sizeof(char) * maxLengthOfString);
    ex->countryOfOrigin = (char *) malloc(sizeof(char) * maxLengthOfString);
}


int readExplorers(FILE *f, explorers *ex) {
    int nrOfExplorers = 0;
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    while (fgets(strbuf, 200, f) != NULL) {
        char *pch;
        pch = strtok(strbuf, ",");
        strcpy(ex[nrOfExplorers].name, pch);
        pch = strtok(NULL, ",");
        strcpy(ex[nrOfExplorers].countryOfOrigin, pch);
        pch = strtok(NULL, ",");
        ex[nrOfExplorers].nrOfDiscoveries = atoi(pch);
        pch = strtok(NULL, ",");
        ex[nrOfExplorers].distFromTheHolyGrail = atoi(pch);
        nrOfExplorers++;
    }
    return nrOfExplorers;
}

void sortExplorersDiscoveries(explorers *ex, int numberOfExplorers) {
    explorers *auxExplorers = (explorers *) malloc(sizeof(explorers) * maxNrOfExplorers);
    for (int i = 0; i < maxNrOfExplorers; i++) {
        initializeExplorers(&auxExplorers[i]);
    }
    int index = 0;
    for (int i = 0; i < numberOfExplorers - 1; i++) {
        for (int j = i + 1; j < numberOfExplorers; j++) {
            if (ex[i].nrOfDiscoveries < ex[j].nrOfDiscoveries) {
                auxExplorers[index] = ex[i];
                ex[i] = ex[j];
                ex[j] = auxExplorers[index];
            }
        }
    }
}


void sortExplorersDistance(explorers *ex, int numberOfExplorers) {
    explorers *auxExplorers = (explorers *) malloc(sizeof(explorers) * maxNrOfExplorers);
    for (int i = 0; i < maxNrOfExplorers; i++) {
        initializeExplorers(&auxExplorers[i]);
    }
    int index = 0;
    for (int i = 0; i < numberOfExplorers - 1; i++) {
        for (int j = i + 1; j < numberOfExplorers; j++) {
            if (ex[i].distFromTheHolyGrail > ex[j].distFromTheHolyGrail) {
                auxExplorers[index] = ex[i];
                ex[i] = ex[j];
                ex[j] = auxExplorers[index];
            }
        }
    }
}

void printExplorers(FILE *o, explorers ex) {
    fprintf(o,"%s,%s,%d,%d\n", ex.name, ex.countryOfOrigin, ex.nrOfDiscoveries, ex.distFromTheHolyGrail);
}

int main() {
    FILE *f;
    f = fopen("explorers.txt", "r");
    explorers *ex = (explorers *) malloc(sizeof(explorers) * maxNrOfExplorers);
    for (int i = 0; i < 20; i++) {
        initializeExplorers(&ex[i]);
    }

    int explorersNum = readExplorers(f, ex);
    int m;
    printf("m= ");
    scanf("%d", &m);
    sortExplorersDiscoveries(ex, m);
    FILE *o;
    o=fopen("discoveriesExplorers.txt", "w");

    for (int i = 0; i < explorersNum; i++) {
        printExplorers(o, ex[i]);
    }

    FILE *h;
    h=fopen("holyGrail.txt","r");
    holyGrail grail;
    char *strbuf=(char*)malloc(sizeof(char)*maxLengthOfString);
    fgets(strbuf,maxLengthOfString,h);
    char *pointer;
    pointer=strtok(strbuf, ",");
    strcpy(grail.countryOfOrigin, pointer);
    pointer=strtok(NULL, ",");
    grail.age=atoi(pointer);

    FILE *s;
    s=fopen("grailExplorers.txt", "w");

    sortExplorersDistance(ex,explorersNum);
    for (int i=0;i<explorersNum;i++)
    {
        printExplorers(s,ex[i]);
    }

    fclose(s);
    fclose(h);
    fclose(o);
    fclose(f);
    return 0;
}