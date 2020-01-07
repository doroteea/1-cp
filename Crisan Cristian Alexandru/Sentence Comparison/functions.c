#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char name;
    int *aparitions;
    int totalApp;
} letter;
void initializeFILES(FILE **r,FILE **w,char *nameOFreadingFILE,char *nameOFwritingFILE)
{
    *r=fopen(nameOFreadingFILE,"r");
    *w=fopen(nameOFwritingFILE,"r+");
}
void initializeLetters(letter **letters,int N)
{
    *letters=(letter*)malloc(sizeof(letter)*26);
    for(int i=0; i<26; i++)
    {(*letters)[i].name='a'+i;
        (*letters)[i].aparitions=(int*)malloc(sizeof(int)*N);
        for(int j=0; j<N; j++)
        {
            (*letters)[i].aparitions[j]=0;

        }
        (*letters)[i].totalApp=0;
    }
}
void readSentences_AND_detAparitions(FILE *f,letter **letters,int N)
{
    initializeLetters(letters,N);
  char litera;
    for(int i=0; i<N; i++)
    {
        while((int)(litera=fgetc(f))!=10)
        {
           //printf("%d da\n",(*letters)[(int)litera-'a'].aparitions[i]);
            (*letters)[(int)litera-'a'].aparitions[i]++;

            (*letters)[(int)litera-'a'].totalApp++;
        }
    }


}
void interchangeLetters(letter *A,letter *B)
{
    letter aux;
    aux=*A;
    *A=*B;
    *B=aux;
}
void sortLettersByNumberOfOccurences(letter *letters)
{
    for(int i=0; i<25; i++)
    {
        for(int j=i+1; j<26; j++)
        {
            if(letters[i].totalApp<letters[j].totalApp)
            {
                interchangeLetters(&letters[i],&letters[j]);
            }
        }
    }
}
void printLettersINfile(letter *letters,FILE *fileTOprintON)
{

    for(int i=0; i<26; i++)
    {
        fprintf(fileTOprintON,"%c=%d\n",letters[i].name,letters[i].totalApp);
    }
}
void comparisonWITHwriting(letter *letters,FILE *fileTOprintON,int m,int N)
{
     char *score=(char*)malloc(sizeof(char)*N);
     for(int i=0;i<N;i++)
     {
         score[i]=0;
     }
     for(int i=0;i<26;i++)
     {
             for(int k=0;k<N;k++)
             {
                 if(k!=m)
                 {
                     if(letters[i].aparitions[m]==letters[i].aparitions[k])
                     {
                         score[k]++;
                     }
                     else {score[k]--;}
                 }
             }

     }
     for(int i=0;i<N;i++)
     {
         if(i!=m)
         {
         fprintf(fileTOprintON,"%d vs. %d =%d\n",m,i,score[i]);
         }
     }
}
