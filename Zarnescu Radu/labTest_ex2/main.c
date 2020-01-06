#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f;
FILE * g;

int main()
{

    /// a)

    int nrOfSentences, i, j, k;
    char letter, cmpLetter;
    f = fopen("sentences.txt", "rw+");
    g = fopen("output.txt", "w");
    fscanf(f, "%d", &nrOfSentences);
    int * freqVect = (int*)malloc(sizeof(int)*26);
    memset(freqVect, 0, 4*26);
    char **sentences = (char**)malloc(sizeof(char*)*nrOfSentences);
    for(i=0; i<nrOfSentences; i++)
    {
        sentences[i] = (char*)malloc(sizeof(char)*26);
    }
    char * sentence = (char*)malloc(sizeof(char)*26);
    fgets(sentence, 150, f);
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
    for(i=0; i<26; i++)
    {
        letter=97+i;
        fprintf(g, "%c=%d\n", letter, freqVect[i]);
    }
    fprintf(g, "\n");

    /// b)

    int m,comp, aux;
    char letter1,letter2;
    printf("m = ");
    scanf("%d",&m);
    for(i=0; i<nrOfSentences; i++)
    {
        memset(freqVect, 0, 4*26);
        comp=0;
        if(i!=m)
        {
            for(j=0; sentences[i][j]!='\0' && sentences[m][j]!='\0'; j++)
            {
                for(k=0; k<26; k++)
                {
                    letter1=sentences[i][j]-97;
                    letter2=sentences[m][j]-97;
                    if(letter1==k)
                    {
                        freqVect[k]++;
                    }
                    if(letter2==k)
                    {
                        freqVect[k]++;
                    }
                }
                for(k=0; k<26; k++)
                {
                    aux = freqVect[k]/2*2;
                    if(aux==freqVect[k] && freqVect[k]!=0)
                    {
                        comp++;
                    }
                    else
                    {
                        comp--;
                    }
                }
            }
            if(sentences[i][j]=='\0')
            {
                comp = comp-(strlen(sentences[m])-strlen(sentences[i]));
            }
            else
            {
                if(sentences[m][j]=='\0')
                {
                    comp = comp-(strlen(sentences[i])-strlen(sentences[m]));
                }
            }
            fprintf(g, "%d vs. %d = %d\n", i, m, comp );
        }
    }

    return 0;
}
