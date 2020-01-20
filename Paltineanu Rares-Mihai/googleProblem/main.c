///se citesc n perechi de 2 sinonime
///sa se determine daca 2 texte citite de la tastatura sunt identice sau nu
///Ex: pt sinonimele mare-ocean, propozitiile Mama are mare si Mama are ocean sunt identice
///Intre 2 sinonime se pune spatiu
/**
the example i tried is:
n = 5
aa bb
bb cc
dd ee
ee ff
ff aa

text1: i am aa
text2: i am ee

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

int arb[100000];

int takeTheFather(int x) {

    if(arb[x] != x) {

        return takeTheFather(arb[x]);

    }

    return x;
}

int hashFunction(char *s) {

    /**
    i tried to make an unique number for every word
    for ex: a will be 1, b will be 2 etc.
        if i have the word abb, the number is 1 * 26^0 + 2 * 26^1 + 2 * 26^2
    */

    int nr = s[0] - 'a' + 1;
    int size = strlen(s);
    int power = 26;

    for(int i = 1; i < size; i++) {

        nr = (nr + (s[i] - 'a' + 1) * (power % MAX))% MAX;
        power = (power * 26) % MAX;

    }


    return nr;

}

void readSyn(char **mat, int n) {

    char *cuv = (char *)malloc(sizeof(char) * 100);
    int nr1, nr2, nr3;
    memset(cuv, 100, '\0');

    for(int i = 0; i < n; i++) {

        gets(mat[i]);
        mat[i] = tolower(mat[i]);

        strcpy(cuv, mat[i]);
        cuv[strlen(cuv) - strlen(strchr(cuv, ' '))] = '\0'; /// first word
        nr1 = hashFunction(cuv);

        if(arb[nr1] == 0) {

            arb[nr1] = nr1;
            nr2 = hashFunction(strrchr(mat[i], ' ') + 1); /// second word

            if(arb[nr2] == 0) {

                arb[nr2] = nr1;

            } else {

                nr3 = takeTheFather(nr2);
                arb[nr2] = nr3;
                arb[nr1] = nr3;

            }
        } else {

            nr3 = takeTheFather(nr1);
            arb[nr1] = nr3;
            nr2 = hashFunction(strrchr(mat[i], ' ') + 1);
            arb[nr2] = nr3;

        }

        printf("arb[%d]=%d arb[%d]=%d\n\n", nr1, arb[nr1], nr2, arb[nr2]);

    }

    printf("\n\n\n\n");
}

void reunionSyn(char **mat, int n) {

    int nrCuv1, nrCuv2, nrFatherCuv1, nrFatherCuv2;
    char *cuv = (char *)malloc(sizeof(char) * 100);

    for(int i = 0; i < n; i++) {

        strcpy(cuv, mat[i]);
        cuv[strlen(cuv) - strlen(strchr(cuv, ' '))] = '\0';

        nrCuv1 = hashFunction(cuv);
        nrCuv2 = hashFunction(strchr(mat[i], ' ') + 1);

        if(arb[nrCuv1] != arb[nrCuv2]) {

            nrFatherCuv1 = takeTheFather(nrCuv1);
            nrFatherCuv2 = takeTheFather(nrCuv2);

            if(nrFatherCuv1 == nrCuv1) {

                arb[nrCuv1] = nrFatherCuv2;

            }
            else {

                arb[nrCuv2] = nrFatherCuv1;

            }

        }

    }

}

void getCuv(char *txt, char *cuv, int i, int size) {

    int sizeCuv = 0;

    while(txt[i] != ' ' && txt[i] != '.' && txt[i] != ',' && txt[i] != '!' && txt[i] != '?'  && i < size) {

        cuv[sizeCuv] = txt[i];
        sizeCuv++;
        i++;

    }

    cuv[sizeCuv] = '\0';

}

int sameTxt(char txt1[200], char txt2[200], char **syn, int n) {

    int nr1, nr2;
    int i = 0, size1 = strlen(txt1);
    int j = 0, size2 = strlen(txt2);
    int sizeCuv1 = 0, sizeCuv2 = 0;
    char *cuv1 = (char *)malloc(sizeof(char) * 100);
    char *cuv2 = (char *)malloc(sizeof(char) * 100);

    getCuv(txt1, cuv1, i, size1);
    getCuv(txt2, cuv2, j, size2);

    while(i < size1 && j < size2) {

        if(strcmp(cuv1, cuv2) != 0) {

            nr1 = hashFunction(cuv1);
            nr2 = hashFunction(cuv2);
            if(arb[nr1] != arb[nr2]) {
                return 0;
            }

        }
        i = i + strlen(cuv1) + 1;
        j = j + strlen(cuv2) + 1;

        getCuv(txt1, cuv1, i + 1, size1);
        getCuv(txt2, cuv2, j + 1, size2);

    }

    if(i >= size1 && j < size2 || i < size1 && j >= size2) {
        return 0;
    }

    return 1;
}

int main() {

    int n;
    printf("Read the value of n: ");
    scanf("%d", &n);
    getchar();

    char **synonyms = (char **)malloc(sizeof(char*) * 50);


    for(int i = 0; i < n; i++) {

        synonyms[i] = (char *)malloc(sizeof(char) * 100);

    }

    printf("Read the synonyms:\n");
    readSyn(synonyms, n);

    reunionSyn(synonyms, n);
    ///unionSynonyms(synonyms, n);

    char *txt1 = (char *)malloc(sizeof(char) * 200);
    char *txt2 = (char *)malloc(sizeof(char) * 200);

    printf("Read the first text:\n");
    gets(txt1);
    txt1 = tolower(txt1);

    printf("Read the second text:\n");
    gets(txt2);
    txt2 = tolower(txt2);

    if(sameTxt(txt1, txt2, synonyms, n) == 1)
        printf("Same texts");
    else
        printf("The text are not the same");

    return 0;

}
