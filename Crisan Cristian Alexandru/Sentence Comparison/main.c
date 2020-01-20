#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <string.h>
int main()
{char *linie=(char*)malloc(sizeof(char)*2);
int N,m;
FILE *r,*w;
initializeFILES(&r,&w,"Sentences.txt","Output.dat");
fgets(linie,100,r);
N=atoi(linie);
letter *letters;
readSentences_AND_detAparitions(r,&letters,N);
sortLettersByNumberOfOccurences(letters);
printLettersINfile(letters,w);
printf("Give the number of the sentence:");
scanf("%d",&m);
comparisonWITHwriting(letters,w,m,N);
fclose(r);
fclose(w);
    return 0;
}
