#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 50

typedef struct
{
    char letter;
    int occurance;
} letterOccurance;
char **readSentences(FILE * f, int N)
{
    char **sentences=(char**)malloc(sizeof(char*)*N);
    for(int i=0; i<N; i++)
    {
        sentences[i]=(char*)malloc(sizeof(char)*MAX_LENGTH);
        fgets(sentences[i],MAX_LENGTH,f);
    }
    return sentences;
}
void formFrequencyMat(int **frequencyMat,char **sentences,int N)
{

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<strlen(sentences[i])-1; j++)
            frequencyMat[i][sentences[i][j]-'a']++;
    }

}
void formFrequencyVector(letterOccurance *frequencyVector,int N,int **frequencyMat)
{
    for(int i=0; i<26; i++)
    {
        frequencyVector[i].letter='a'+i;
        frequencyVector[i].occurance=0;
        for(int j=0; j<N; j++)
            frequencyVector[i].occurance+=frequencyMat[j][i];
    }
}
void sortFrequencyVector(letterOccurance *frequencyVector)
{
    letterOccurance aux;
    for(int i=0; i<25; i++)
    {
        for(int j=i+1; j<26; j++)
        {
            if(frequencyVector[i].occurance<frequencyVector[j].occurance)
            {
                aux=frequencyVector[i];
                frequencyVector[i]=frequencyVector[j];
                frequencyVector[j]=aux;
            }
        }
    }
}
void displayLetterOccurance(letterOccurance *frequencyVector)
{
    for(int i=0; i<26; i++)
    {
        printf("%c=%d\n",frequencyVector[i].letter,frequencyVector[i].occurance);
    }
}
void displayComparison(int **frequencyMat, int m, int N)
{
    int comparisonSum;
    for(int i=0; i<N; i++)
    {
        comparisonSum=0;
        for(int j=0; j<26; j++)
        {
            if(frequencyMat[m][j]==frequencyMat[i][j])
            {
                comparisonSum++;
            }
            else
            {
                comparisonSum--;
            }
        }
        printf("%d vs. %d = %d\n",i,m,comparisonSum);
    }
}
int main()
{
    int N,m;
    FILE *f=fopen("sentences.txt","r");
    fscanf(f,"%d\n",&N);
    char **sentences = readSentences(f,N);
    letterOccurance *frequencyVector=(letterOccurance*)malloc(sizeof(letterOccurance)*26);
    int **frequencyMat=(int**)malloc(sizeof(int*)*N);
    for(int i=0; i<N; i++)
    {
        frequencyMat[i]=(int*)malloc(sizeof(int)*26);
        for(int j=0; j<26; j++)
        {
            frequencyMat[i][j]=0;
        }
    }

    formFrequencyMat(frequencyMat,sentences,N);
    formFrequencyVector(frequencyVector,N,frequencyMat);
    sortFrequencyVector(frequencyVector);
    displayLetterOccurance(frequencyVector);
    printf("Please input m\nm=");
    scanf("%d",&m);
    displayComparison(frequencyMat,m,N);
    return 0;
}
