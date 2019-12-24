#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N_MAX 100
#define MAX_LENGTH 100
#define LETTERS_IN_ALPHABET 26

typedef struct
{
    int occ;
    char letter;
} letter;

void initLetters (letter *letters)
{
    for (int i=0; i<LETTERS_IN_ALPHABET; i++)
    {
        letters[i].letter = i+'a';
        letters[i].occ = 0;
    }
}

void initArray (int *a)
{
    for (int i=0; i<LETTERS_IN_ALPHABET; i++)
    {
        *(a+i)=0;
    }
}

void readSentences(char **sentence, int n, FILE *f)
{
    for (int i=0; i<n; i++)
    {
        sentence[i]=(char*)malloc(sizeof(char)*MAX_LENGTH);
        fgets(sentence[i], MAX_LENGTH, f);
    }
    fclose(f);
}

void countLetters (char **sentence, letter *letters, int n)
{
    initLetters(letters);

    for(int i=0; i<n; i++)
    {
        int j=0;
        while (sentence[i][j]!=NULL)
        {
            letters[sentence[i][j]-'a'].occ++;
            j++;
        }
    }
}

void sortLetters(letter *letters)
{
    bool isSorted=true;
    do
    {
        isSorted=true;
        for (int i=0; i<25; i++)
        {
            if (letters[i].occ<letters[i+1].occ)
            {
                isSorted = false;
                letter aux=letters[i];
                letters[i]=letters[i+1];
                letters[i+1]=aux;
            }
        }
    }
    while(!isSorted);
}

void printLetters(letter *letters, FILE *g)
{
    for (int i=0; i<LETTERS_IN_ALPHABET; i++)
    {
        if (letters[i].occ>0)
        {

            fprintf(g, "%c=%d\n", letters[i].letter, letters[i].occ);
        }
    }
    fprintf(g, "\n");

}


void count (char* sentence, int *letters)
{
    int i=0;
    while (sentence[i]!=NULL)
    {
        letters[sentence[i]-'a']++;
        i++;
    }

}

int compare(int *a, int *b)
{
    int s=0;
    for (int i=0; i<LETTERS_IN_ALPHABET; i++)
    {
        if (a[i]==b[i] && (a[i]+b[i]!=0))
        {
            s++;
        }
        else
        {
            s--;
        }
    }
    return s;
}

void printLetterComparison(char **sentences, int m, int n, FILE *g)
{
    int *occSentenceM = (int*)malloc(sizeof(int)*LETTERS_IN_ALPHABET);
    initArray(occSentenceM);

    count(sentences[m], occSentenceM);

    for (int i=0; i<n; i++)
    {

        int *occI = (int*) malloc(sizeof(int)*LETTERS_IN_ALPHABET);
        initArray(occI);
        count(sentences[i], occI);

        int outcome = compare(occSentenceM, occI);

        fprintf(g, "%d vs. %d = %d\n", i, m, outcome);

        free(occI);

    }

}
int main()
{
    FILE *f = fopen("Sentences.dat", "r");
    int n;
    fscanf(f,"%d\n", &n);

    letter *letters = (letter*)malloc(sizeof(letter)*LETTERS_IN_ALPHABET);
    char **sentence = (char**)malloc(sizeof(char**)*n);

    readSentences(sentence, n, f);
    countLetters(sentence, letters, n);
    sortLetters(letters);

    FILE *g = fopen("Output.dat", "w");
    printLetters(letters, g);

    int m;
    printf("m = ");
    scanf("%d", &m);

    printLetterComparison(sentence, m, n, g);
    fclose(g);
    return 0;
}
