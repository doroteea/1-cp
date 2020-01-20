#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **initializeChar(int n) {

    char **mat = (char **)malloc(sizeof(char *) * n );

    for(int i = 0; i < n; i++) {

        mat[i] = (char *)malloc(sizeof(char) * 100);
    }
    return mat;
}

int **initializeInt(int n) {

    int **mat = (int **)malloc(sizeof(int *) * n);

    for(int i = 0; i < n; i++) {

        mat[i] = (int *)malloc(sizeof(int) * 27);

        memset(mat[i], 0, sizeof(int) * 27);
    }
    return mat;
}

void initAllLetter(int **all) {

    for(int i = 0; i < 27; i++) {

        all[0][i] = i;
    }
}

void convertingIntoLower(char *array) {

    int size = strlen(array);

    for(int i = 0; i < size; i++) {

        array[i] = tolower(array[i]);
    }
}

void countingLetterOccurence(int **allLetter, int **mat, char **matChar, int n) {

    for(int i = 0; i < n; i++) {

        int size = strlen(matChar[i]);

        for(int j = 0; j < size; j++) {

            if(matChar[i][j] != '\n') {

                mat[i][matChar[i][j] - 'a']++;
                allLetter[1][matChar[i][j] - 'a']++;
            }

        }
    }
}

void read(char **mat, int n, FILE *f) {

    for(int i = 0; i < n; i++) {

        fgets(mat[i], 100, f);
        convertingIntoLower(mat[i]);
        puts(mat[i]);
    }
}

void sort(int **allLetter) {

    bool gata = false;
    int aux;

    while(!gata) {

        gata = true;

        for(int i = 0; i < 25; i++) {

            if(allLetter[1][i] > allLetter[1][i + 1]) {

                gata = false;

                aux = allLetter[1][i];
                allLetter[1][i] = allLetter[1][i + 1];
                allLetter[1][i + 1] = aux;

                aux = allLetter[0][i];
                allLetter[0][i] = allLetter[0][i + 1];
                allLetter[0][i + 1] = aux;
            }
        }
    }
}

void comparison(int **letterOccurence, int m, int n) {

    int comp = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < 26; j++) {


            if(letterOccurence[i][j] != letterOccurence[m][j]) {

                comp--;
            } else {

                comp++;
            }

        }

        printf("%d vs %d = %d\n", i, m, comp);

        comp = 0;
    }

}

int main() {

    FILE *f;
    f = fopen("sentences.dat", "r");

    if(f == NULL) {

        return -1;
    }

    int n, m;
    fscanf(f,"%d %d\n", &n, &m);

    if(n < 0 || m >= n || m < 0) {

        printf("N and m must be positive and n greater than m");
        return -1;
    }

    char **sentences = initializeChar(n);
    read(sentences, n, f);

    int **letterOccurence = initializeInt(n);
    int **allLetterOccurence = initializeInt(2);
    initAllLetter(allLetterOccurence);

    countingLetterOccurence(allLetterOccurence, letterOccurence, sentences, n);
    sort(allLetterOccurence);

    for(int i = 0; i < 26; i++) {

        printf("%c = %d\n", 'a' + allLetterOccurence[0][i], allLetterOccurence[1][i]);

    }

    comparison(letterOccurence, m, n);
    return 0;
}
