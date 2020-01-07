#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAXNrOfSentances=200;
const int MAXLenghtOfTheSentances=200;

typedef struct
{
    int occurance;
    char symbol;
}characters;

char ** readSentences(FILE * f)
{
    char ** sentences = (char**)malloc(sizeof(char**)*MAXNrOfSentances);

    for(int i=0; i<MAXNrOfSentances; i++)
    {
        sentences[i] = (char*)malloc(sizeof(char)*MAXNrOfSentances);
        fgets(sentences[i],MAXLenghtOfTheSentances,f);
    }

    return sentences;
}
characters *Initialize(int NrOfCharactersInAlphabet)
{   int i;
    characters *c=(characters *) malloc (sizeof(characters)*NrOfCharactersInAlphabet);
    char character='a';
    for(i=0;i<26;i++)
    {
        c[i].occurance=0;
        c[i].symbol=character;
        character=character+('b'-'a');
    }
    return c;

}
characters *Form(char **sentences)
{    int i,j;
     characters *c=Initialize(26);
     for(i=0;i<8;i++)
        for(j=0;j<strlen(sentences[i]);j++)
     {
         for(int k=0;k<26;k++)
            if(sentences[i][j]==c[k].symbol) c[k].occurance++;
     }
     return c;
}
characters *Sort(char **sentences)
{   int i,j,aux;
    char caux;
    characters *c=Form(sentences);
    for(i=0;i<25;i++)
        for(j=i;j<26;j++)
        if(c[i].occurance<c[j].occurance)
    {
        aux=c[i].occurance;
        c[i].occurance=c[j].occurance;
        c[j].occurance=aux;
        caux=c[i].symbol;
        c[i].symbol=c[j].symbol;
        c[j].symbol=caux;

    }
    return c;
}

int verify (char **sentences,int nr,int Index)
{  int j,k,comp=0;
    characters *c=Initialize(26);
     for(j=0;j<strlen(sentences[nr]);j++)
     {
         for( k=0;k<26;k++)
            if(sentences[nr][j]==c[k].symbol) c[k].occurance++;
     }
     for(j=0;j<strlen(sentences[Index]);j++)
     {
         for( k=0;k<26;k++)
            if(sentences[Index][j]==c[k].symbol) c[k].occurance--;
     }
    for( k=0;k<26;k++)
    {
        if(c[k].occurance==0) comp++;
        else comp--;
    }
    return comp;
}



int main()
{   int nr,i,comp;
    FILE * f = fopen("sentances.txt", "r+");
    FILE * g = fopen("output.txt", "r+");
    char ** sentences = readSentences(f);
    characters *c=Sort(sentences);
    for(int i=0;i<26;i++)
        fprintf(g,"%c = %d \n",c[i].symbol,c[i].occurance);
    scanf("%d",&nr);
    for(i=0;i<8;i++)
    {
        comp=verify (sentences,nr,i);
        fprintf(g,"%d vs %d = %d\n",i,nr,comp);
    }


    return 0;
}
