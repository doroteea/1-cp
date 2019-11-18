#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///la ambele functii am problema asta:
///merge bine in main dar in functie author[i] de ex este (null) orice as face
void printAlphabeticalAuthors(char **author, int nrBooks)
{
    int i,j;
    for(i=1; i<nrBooks; i++)
    {
        for(j=i; j<=nrBooks; j++)
        {
            int a = strcmp(author[i],author[j]);
            if(a>0)
            {
                char aux[1001];
                strcpy(aux,author[i]);
                strcpy(author[i],author[j]);
                strcpy(author[j],aux);
            }
        }
    }

    printf("The aphabetical order of the authors is:\n");
    for(i=1; i<=nrBooks; i++)
    {
        printf("\t %s \n",author[i]);
    }
}


void orderPublicationYears( char **author, char **title, int *publicationYear, int nrBooks)
{
    int initialPosition[2][1001];
    int i,j;
    for(i=1; i<=nrBooks; i++)
    {
        initialPosition[1][i]=i;
        initialPosition[2][i] = publicationYear[i];
    }

    for(i=1; i<nrBooks; i++)
    {
        for(j=i; j<=nrBooks; j++)
        {
            if(initialPosition[2][i] > initialPosition[2][j])
            {
                int aux;
                aux = initialPosition[1][i];
                initialPosition[1][i] = initialPosition[1][j];
                initialPosition[1][j] = aux;

                aux = initialPosition[2][i];
                initialPosition[2][i] = initialPosition[2][j];
                initialPosition[2][j] = aux;
            }
        }
    }

    printf("The order of authors and titles sorted by their publication years is:\n");
    for(i=1;i<=nrBooks; i++)
    {
        printf("\t%d. %s, %s\n",i,author[i],title[i]);
    }
}


int main()
{
    int nrBooks,i;
    scanf("%d",&nrBooks);

    int *publicationYear = (int*)malloc(sizeof(int)*nrBooks);

    char author[1001][1001];
    char title[1001][1001];

    for(i=1; i<=nrBooks; i++)
    {
        printf("Input the author of book nr. %d: ",i);
        scanf("%s",&author[i]);
        printf("Input the title of book nr. %d: ",i);
        scanf("%s",&title[i]);
        printf("Input the publication year of book nr. %d: ",i);
        scanf("%d",&publicationYear[i]);
        printf("\n");
    }


    printAlphabeticalAuthors(author,nrBooks);
    orderPublicationYears(author, title, *publicationYear,nrBooks);


    return 0;
}
