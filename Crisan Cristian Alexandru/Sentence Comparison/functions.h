#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name;
    int *aparitions;
    int totalApp;
} letter;
void initializeFILES(FILE **r,FILE **w,char *nameOFreadingFILE,char *nameOFwritingFILE);
void readSentences_AND_detAparitions(FILE *f,letter **letters,int N);
void sortLettersByNumberOfOccurences(letter *letters);
void printLettersINfile(letter *letters,FILE *fileTOprintON);

