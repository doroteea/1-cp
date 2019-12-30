#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *** allocateString(int rows,int columns,int string_length)
{
    char *** string=(char***)malloc(sizeof(char**)*rows);
    for(int i=0; i<rows; i++)
    {
        string[i]=(char**)malloc(sizeof(char*)*columns);
        for(int j=0; j<columns; j++)
        {
            *(*(string+i)+j)=(char*)malloc(sizeof(char)*string_length);
        }
    }
    return string;
}
char *** readString(int rows,int columns,int string_length)
{
    char *** string=allocateString(rows,columns,string_length);
    for(int i=0; i<rows; i++)
    {
        printf("Please insert the author, the title and the publication year:\n");
        getchar();
        for(int j=0; j<columns; j++)
        {
            gets(*(*(string+i)+j));
        }
    }
    return string;
}

void printString(char *** string,int rows,int columns)
{
    for(int i=0; i<rows; i++)
    {

        for(int j=0; j<columns; j++)
        {
            printf("%s ",*(*(string+i)+j));
        }
        printf("\n");
    }
}

char ** readStringAlpha(char *** string,int columns,int string_length)
{
    char ** stringAlphabetical=(char**)malloc(sizeof(char*)*columns);
    for(int i=0; i<columns; i++)
    {
        *(stringAlphabetical+i)=(char*)malloc(sizeof(char)*string_length);
        strcpy(*(stringAlphabetical+i),*(*(string+i)));
    }
    return stringAlphabetical;
}

char ** orderStringAlphabeticalAutors(char ** stringAlphabetical,int columns)
{
    int done=0;
    char * aux;
    while(done!=1)
    {
        done=1;
        for(int i=0;i<columns-1;i++)
        {
            if(strcmp(*(stringAlphabetical+i),*(stringAlphabetical+i+1))>0)
            {
                aux=*(stringAlphabetical+i);
                *(stringAlphabetical+i)=*(stringAlphabetical+i+1);
                *(stringAlphabetical+i+1)=aux;
                done=0;
            }
        }
    }
    return stringAlphabetical;
}
void firstOrder(char *** string,int columns,int string_length)
{
    char ** stringAlphabetical=readStringAlpha(string,columns,string_length);
    stringAlphabetical=orderStringAlphabeticalAutors(stringAlphabetical,columns);
    for(int i=0;i<columns;i++)
    {
        printf("%s  ",*(stringAlphabetical+i));
    }
    printf("\n");
}

void secondOrder(char *** string,int rows,int columns)
{
    int done=0,j=columns-1;
    char * aux;
    while(done!=1)
    {
        done=1;
        for(int i=0;i<rows-1;i++)
        {
            if(strcmp(*(*(string+i)+j),*(*(string+i+1)+j))>0)
            {
                for(int k=0;k<columns;k++)
                {
                    aux=*(*(string+i)+k);
                    *(*(string+i)+k)=*(*(string+i+1)+k);
                    *(*(string+i+1)+k)=aux;
                    done=0;
                }
            }
        }
    }
    printString(string,rows,columns);
}
