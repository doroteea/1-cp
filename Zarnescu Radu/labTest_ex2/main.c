#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;
FILE * g;

char * sentence;
char **sentences;
int * freqVect;
int * freqVect2;

void initialization(int nrOfSentences)
{

    int i;
    freqVect = (int*)malloc(sizeof(int)*26);
    freqVect2 = (int*)malloc(sizeof(int)*26);
    memset(freqVect, 0, 4*26);
    sentences = (char**)malloc(sizeof(char*)*nrOfSentences);
    for(i=0; i<nrOfSentences; i++)
    {
        sentences[i] = (char*)malloc(sizeof(char)*26);
    }
    sentence = (char*)malloc(sizeof(char)*26);
}

void readSentences(int nrOfSentences, char * sentence, int * freqVect)
{
    int i,j,k;
    char cmpLetter, letter;
    for(i=0; i<nrOfSentences; i++)
    {
        fgets(sentence, 150, f);
        strcpy(sentences[i], sentence);
    }
    for(i=0; i<nrOfSentences; i++)
    {
        j=0;
        while(sentences[i][j]!='\0')
        {
            letter =sentences[i][j];
            for(k=0; k<26; k++)
            {
                cmpLetter=97+k;
                if(letter==cmpLetter)
                {
                    freqVect[k]++;
                    break;
                }
            }
            j++;
        }
    }
}
void printSentences(int * freqVect)
{
    int i;
    char letter;
    for(i=0; i<26; i++)
    {
        letter=97+i;
        fprintf(g, "%c=%d\n", letter, freqVect[i]);
    }
    fprintf(g, "\n");
}

void compareSentences(int nrOfSentences, int *freqVect, int *freqVect2, char **sentences, int m)
{
    int comp,i , j, k;
    for(i=0; i<nrOfSentences; i++)
    {
        memset(freqVect, 0, 4*26);
        memset(freqVect2, 0, 4*26);
        comp=0;
        if(i!=m)
        {
            for(j=0; sentences[i][j]!='\0'; j++)
            {
                freqVect[sentences[i][j]-97]++;
            }
            for(j=0; sentences[m][j]!='\0'; j++)
            {
                freqVect2[sentences[m][j]-97]++;
            }
            for(k=0; k<26; k++)
            {
                if(freqVect[k]==freqVect2[k] && freqVect[k]!=0)
                {
                    comp++;
                }
                else
                {
                    if(freqVect[k]!=0 || freqVect2[k]!=0)
                    {
                        comp--;
                    }
                }
            }
            fprintf(g, "%d vs. %d = %d\n", i, m, comp );
        }
    }
}

int main()
{

    /// a)

    int nrOfSentences;
    f = fopen("sentences.txt", "rw+");
    g = fopen("output.txt", "w");
    fscanf(f, "%d", &nrOfSentences);
    initialization(nrOfSentences);
    fgets(sentence, 150, f);
    readSentences(nrOfSentences, sentence, freqVect);
    printSentences(freqVect);

    /// b)

    int m;
    printf("m = ");
    scanf("%d",&m);
    compareSentences(nrOfSentences, freqVect, freqVect2, sentences, m);
    return 0;
}
