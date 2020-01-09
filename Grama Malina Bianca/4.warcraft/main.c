#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int req = 100;
const int maxNumberOfHeroes = 30;
const int maxNumberOfQuests = 30;

typedef struct {
    char *name;
    char class;
    int power;
} heroes;

typedef struct {
    char *title;
    char *requiredClasses;
    int requiredTotalPower;
    int experienceGained;
} quests;

typedef struct {
    int damagers;
    int healers;
    int tanks;
} nrOfClasses;

void initializeHeroes(heroes *her) {
    her->name = (char *) malloc(sizeof(char) * 30);
}

void initializeQuests(quests *ques) {
    ques->title = (char *) malloc(sizeof(char) * 50);
    ques->requiredClasses = (char *) malloc(sizeof(char) * 30);
}

void printHeroes(heroes her) {
    printf("%s,%c,%d\n", her.name, her.class, her.power);
}

void printQuests(quests ques) {
    printf("%s,%s,%d,%d\n", ques.title, ques.requiredClasses, ques.requiredTotalPower, ques.experienceGained);
}

void sortHeroes(heroes *her, int nrOfHeroes) {
    int damagers = 0, healers = 0, tanks = 0;
    for (int i = 0; i < nrOfHeroes; i++) {
        if (her[i].class == 'D') {
            damagers++;
        }
        if (her[i].class == 'H') {
            healers++;
        }
        if (her[i].class == 'T') {
            tanks++;
        }
    }

    heroes *auxHeroes = (heroes *) malloc(sizeof(heroes) * maxNumberOfHeroes);
    for (int i = 0; i < maxNumberOfHeroes; i++) {
        initializeHeroes(&auxHeroes[i]);
    }
    int index = 0;
    for (int i = 0; i < nrOfHeroes - 1; i++) {
        for (int j = i + 1; j < nrOfHeroes; j++) {
            if (her[i].class > her[j].class) {
                auxHeroes[index] = her[i];
                her[i] = her[j];
                her[j] = auxHeroes[index];
            }
        }
    }

    for (int i = 0; i < damagers - 1; i++) {
        for (int j = i + 1; j < damagers; j++) {
            if (her[i].power < her[j].power) {
                auxHeroes[index] = her[i];
                her[i] = her[j];
                her[j] = auxHeroes[index];
            }
        }
    }

    for (int i = damagers; i < damagers + healers - 1; i++) {
        for (int j = i + 1; j < damagers + healers; j++) {
            if (her[i].power < her[j].power) {
                auxHeroes[index] = her[i];
                her[i] = her[j];
                her[j] = auxHeroes[index];
            }
        }
    }

    for (int i = damagers + healers; i < nrOfHeroes - 1; i++) {
        for (int j = i + 1; j < nrOfHeroes; j++) {
            if (her[i].power < her[j].power) {
                auxHeroes[index] = her[i];
                her[i] = her[j];
                her[j] = auxHeroes[index];
            }
        }
    }
}

void howManyClasses(quests ques, nrOfClasses *classes) {
    for (int i = 0; i < strlen(ques.requiredClasses); i++) {
        if (ques.requiredClasses[i] == 'D')
            classes->damagers++;
        if (ques.requiredClasses[i] == 'H')
            classes->healers++;
        if (ques.requiredClasses[i] == 'T')
            classes->tanks++;
    }
}

int main() {
    FILE *f;
    f = fopen("heroes.txt", "r+");

    heroes *her = (heroes *) malloc(sizeof(heroes) * 20);
    for (int i = 0; i < 20; i++) {
        initializeHeroes(&her[i]);
    }

    quests *ques = (quests *) malloc(sizeof(quests) * 20);
    for (int i = 0; i < 20; i++) {
        initializeQuests(&ques[i]);
    }

    int nrOfHeroes = 0;
    char *strbuf = (char *) malloc(sizeof(char) * 200);
    while (fgets(strbuf, 200, f) != NULL) {
        char *pch;
        pch = strtok(strbuf, ",");
        strcpy(her[nrOfHeroes].name, pch);
        pch = strtok(NULL, ",");
        her[nrOfHeroes].class = *pch;
        pch = strtok(NULL, ",");
        her[nrOfHeroes].power = atoi(pch);
        nrOfHeroes++;
    }

    FILE *q;
    q = fopen("quests.txt", "r");
    int qNum = 0;
    char *buffer = (char *) malloc(sizeof(char) * 200);
    while (fgets(buffer, 200, q) != NULL) {
        char *pointer;
        pointer = strtok(buffer, ",");
        strcpy(ques[qNum].title, pointer);
        pointer = strtok(NULL, ",");
        strcpy(ques[qNum].requiredClasses, pointer);
        pointer = strtok(NULL, ",");
        ques[qNum].requiredTotalPower = atoi(pointer);
        pointer = strtok(NULL, ",");
        ques[qNum].experienceGained = atoi(pointer);
        qNum++;
    }

    sortHeroes(her, nrOfHeroes);
    nrOfClasses *classes = (nrOfClasses *) malloc(sizeof(nrOfClasses) * maxNumberOfQuests);
    for (int i = 0; i < qNum; i++) {
        howManyClasses(ques[i], &classes[i]);
    }

    FILE *output;
    output = fopen("outcome.txt", "w");
    int damagers = 0, healers = 0, tanks = 0;
    for (int i = 0; i < nrOfHeroes; i++) {
        if (her[i].class == 'D') {
            damagers++;
        }
        if (her[i].class == 'H') {
            healers++;
        }
        if (her[i].class == 'T') {
            tanks++;
        }
    }

    int experienceGained = 0;
    for (int i = 0; i < qNum; i++) {
        int totalPower = 0;
        if (classes[i].damagers <= damagers) {
            if (classes[i].healers <= healers) {
                if (classes[i].tanks <= tanks) {
                    for (int j = 0; j < classes[i].damagers; j++) {
                        fprintf(output,"%s, ", her[j].name);
                        totalPower = totalPower + her[j].power;
                    }
                    for (int k = damagers; k < damagers + classes[i].healers; k++) {
                        fprintf(output,"%s, ", her[k].name);
                        totalPower = totalPower + her[k].power;
                    }
                    for (int a = damagers + healers; a < damagers + healers + classes[i].tanks; a++) {
                        fprintf(output,"%s, ", her[a].name);
                        totalPower = totalPower + her[a].power;
                    }
                    experienceGained = experienceGained + ques[i].experienceGained;
                    fprintf(output,"went on to complete \"%s\" - SUCCESS (%d vs %d) and gained %dxp.", ques[i].title,
                           ques[i].requiredTotalPower, totalPower, ques[i].experienceGained);
                } else {
                    fprintf(output,"Cannot execute mission \"%s\" - not enough heroes of type \"T\".", ques[i].title);
                }
            } else {
                fprintf(output,"Cannot execute mission \"%s\" - not enough heroes of type \"H\".", ques[i].title);
            }
        } else {
            fprintf(output,"Cannot execute mission \"%s\" - not enough heroes of type \"D\".", ques[i].title);
        }
        fprintf(output,"\n");
    }

    fprintf(output,"\nThe group gained a total of %d XP.\n", experienceGained);
    if (experienceGained < req) {
        fprintf(output,"Cannot attack Argus :(");
    } else {
        fprintf(output,"The group is now ready to attack Argus :)");
    }

    fclose(f);
    fclose(q);
    fclose(output);
    return 0;
}