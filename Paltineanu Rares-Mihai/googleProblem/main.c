///se citesc n perechi de 2 sinonime
///sa se determine daca 2 texte citite de la tastatura sunt identice sau nu
///Ex: pt sinonimele mare-ocean, propozitiile Mama are mare si Mama are ocean sunt identice
///Intre 2 sinonime se pune spatiu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void readSyn(char **mat, int n) {

    for(int i = 0; i < n; i++) {
        gets(mat[i]);
        mat[i] = tolower(mat[i]);
    }
}

int findCuvinSyn(char *cuv, char **syn, int n) {

    for(int i = 0; i < n; i++) {
        if(strncmp(cuv, syn[i], strlen(cuv)) == 0 || strcmp(cuv, strrchr(syn[i], ' ') + 1) == 0) {
            return i;
        }
    }

    return -1;
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


    int i = 0, size1 = strlen(txt1);
    int j = 0, size2 = strlen(txt2);
    int sizeCuv1 = 0, sizeCuv2 = 0;
    char *cuv1 = (char *)malloc(sizeof(char) * 100);
    char *cuv2= (char *)malloc(sizeof(char) * 100);


    getCuv(txt1, cuv1, i, size1);
    getCuv(txt2, cuv2, j, size2);
    while(i < size1 && j < size2) {

        if(strcmp(cuv1, cuv2) != 0) {

            if(findCuvinSyn(cuv1, syn, n) == -1 && findCuvinSyn(cuv2, syn, n) == -1
                    || findCuvinSyn(cuv1, syn, n) != findCuvinSyn(cuv2, syn, n))  {
                return 0;
            }

        }
        i = i + strlen(cuv1) + 1;
        j = j + strlen(cuv2) + 1;

        getCuv(txt1, cuv1, i + 1, size1);
        getCuv(txt2, cuv2, j + 1, size2);

    }

    return 1;
}

int main() {

    int n;
    printf("Read the value of n: ");
    scanf("%d", &n);
    getchar();
    char **synonyms = (char **)malloc(sizeof(char*) * n);

    for(int i = 0; i < n; i++) {
        synonyms[i] = (char *)malloc(sizeof(char) * 100);
    }
    printf("Read the synonyms:\n");
    readSyn(synonyms, n);



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
