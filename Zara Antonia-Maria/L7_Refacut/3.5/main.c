///3.5. Write a function to sort ascending n character strings.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **read(int nrStrings)
{
    int i;
    char **a = (char**)malloc(sizeof(char*)*nrStrings);

    for(i=0; i<nrStrings; i++)
    {
        *(a+i) = (char*)malloc(sizeof(char)*20);
    }

    for(i=0; i<nrStrings; i++)
    {
        scanf("%s",a[i]);
    }

    return a;
}

void sortStrings(char **matrix, int nrStrings)
{
    int i,j;
    char *aux = (char*)malloc(sizeof(char)*20);

    for(i=0; i<nrStrings-1; i++)
    {
        for(j=i; j<nrStrings; j++)
        {
            if(strcmp(matrix[i],matrix[j])>0)
            {
                strcpy(aux,matrix[i]);///aux = matrix[i];
                strcpy(matrix[i],matrix[j]);///matrix[i] = matrix[j];
                strcpy(matrix[j],aux);///matrix[j] = aux;
            }
        }

    }
}

void printSortedStrings(char **matrix, int nrStrings)
{
    int i;
    for(i=0; i<nrStrings; i++)
    {
        printf("%s\n",matrix[i]);
    }
}

int main()
{
    int nrStrings,i;
    printf("Please input the number of strings: ");
    scanf("%d",&nrStrings);

    char **matrix = (char**)malloc(sizeof(char*)*nrStrings);
    for(i=0; i<nrStrings; i++)
    {
        *(matrix+i) = (char*)malloc(sizeof(char)*20);
    }

    matrix = read(nrStrings);
    sortStrings(matrix,nrStrings);
    printSortedStrings(matrix,nrStrings);

    return 0;
}
