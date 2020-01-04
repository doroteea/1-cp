#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

char ** initSentences(char ** s)
{
    s=(char **) malloc(sizeof (char *)*MAXIMUM_NR_OF_SENTENCES);

    for(int i=0; i<MAXIMUM_NR_OF_SENTENCES; i++)
    {
        s[i]=(char *) malloc(MAXIMUM_LENGTH_OF_SENTENCE);
    }
    return s;
}

int readSentences(char **s,FILE *ff,int nr)
{
    char empty[NR_OF_ALPHABET_LETTERS];
    fgets(empty, NR_OF_ALPHABET_LETTERS, ff); /// empty the buffer

    for(int i=0; i<nr; i++)
    {
        fgets(s[i], NR_OF_ALPHABET_LETTERS+2, ff);
    }

    int sentenceIndex;
    fscanf (ff, "%d", &sentenceIndex);
    return sentenceIndex;
}

lettersAndOccurences** initFr(lettersAndOccurences **fr)
{
    fr=(lettersAndOccurences **) malloc(sizeof(lettersAndOccurences *)*MAXIMUM_NR_OF_SENTENCES);

    for(int i=0; i<MAXIMUM_NR_OF_SENTENCES; i++)
    {
        fr[i]=(lettersAndOccurences*) malloc(sizeof(lettersAndOccurences)*NR_OF_ALPHABET_LETTERS);

        for(int j=0; j<NR_OF_ALPHABET_LETTERS; j++)
        {
            fr[i][j].letter=i+97;
            fr[i][j].occurences=0;
        }
    }
    return fr;
}

lettersAndOccurences *initSumFr(lettersAndOccurences *sumFr)
{
    sumFr=(lettersAndOccurences*) malloc(sizeof(lettersAndOccurences)*NR_OF_ALPHABET_LETTERS);

    for(int i=0; i<NR_OF_ALPHABET_LETTERS; i++)
    {
        sumFr[i].letter=i+97;
        sumFr[i].occurences=0;
    }

    return sumFr;
}

void findlettersOccurences(char **s,int nr,lettersAndOccurences **fr)
{
    for(int i=0; i<nr; i++)
    {
        for(int j=0; s[i][j]!=NULL; j++)
        {
            if(isalpha(s[i][j]))
            {
                char ch=tolower(s[i][j]);
                fr[i][ch-97].occurences++;
            }
        }
    }
}

void sumFrequencies(lettersAndOccurences *sumFr,lettersAndOccurences **fr,int nr)
{
    for(int i=0; i<nr; i++)
    {
//        if(fr[i][14].occurences!=0)
//        {
//            printf("%d \n",i);
//        }
        for(int j=0; j<NR_OF_ALPHABET_LETTERS; j++)
        {
            sumFr[j].occurences+=fr[i][j].occurences;
        }
    }
}

void sortOccurences(lettersAndOccurences *fr)
{
    for(int i=0; i<NR_OF_ALPHABET_LETTERS; i++)
    {
        for(int j=i+1; j<NR_OF_ALPHABET_LETTERS-1; j++)
        {
            if(fr[i].occurences<fr[j].occurences)
            {
                lettersAndOccurences aux=fr[i];
                fr[i]=fr[j];
                fr[j]=aux;
            }
        }
    }
}

void outputOccurences(lettersAndOccurences *fr,FILE *out)
{
    for(int i=0; i<26; i++)
    {
//        fputc('=',out);
        // printf("%d \n",fr[i].occurences);
        fputc(fr[i].letter,out);
        fputc('=',out);
        fputc(fr[i].occurences+48,out);
        fputc('\n',out);
    }
}

void compare(lettersAndOccurences **fr,int nr,int index,FILE *out)
{
    for(int i=0; i<nr; i++)
    {
        int score=0;
        for(int j=0; j<NR_OF_ALPHABET_LETTERS; j++)
        {
            if(fr[i][j].occurences==fr[index][j].occurences)
            {
                score++;
            }
            else
            {
                score--;
            }
        }
        fputc('\n',out);
        fprintf(out,"%d vs %d = %d",i,index,score);
    }
}

int main()
{
    char ** sentences;
    lettersAndOccurences ** freq;
    lettersAndOccurences *sumFreq;
    int nrOfSentences=0;
    FILE *f=fopen("Sentences.dat.txt", "r");
    FILE *o=fopen("Output.dat.txt", "w");

    sentences=initSentences(sentences);
    freq=initFr(freq);
    sumFreq=initSumFr(sumFreq);

    fscanf (f, "%d", &nrOfSentences);
    int sentenceIndex=readSentences(sentences,f,nrOfSentences);

    findlettersOccurences(sentences,nrOfSentences,freq);

    sumFrequencies(sumFreq,freq,nrOfSentences);

    sortOccurences(sumFreq);

    outputOccurences(sumFreq,o);

    compare(freq,nrOfSentences,sentenceIndex,o);

    fclose(f);
    fclose(o);

    return 0;
}
