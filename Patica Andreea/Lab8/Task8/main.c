#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MaxLen 300

int n;

void swap (char*a, char *b)
{
    char *aux=(char*)malloc(sizeof(char)*n);
    strcpy(aux, a);
    strcpy(a, b);
    strcpy(b, aux);
}

int main()
{
    printf("Insert the number of books!\n");
    scanf("%d", &n);

    char **author=(char**)malloc(sizeof(char)*n);
    char **title=(char**)malloc(sizeof(char)*n);
    int *year=(int*)malloc(sizeof(int)*n);

    printf("Insert the name of the author, the title and the publication year for each book!\n");
    for (int i=0; i<n; i++)
    {
        author[i]=(char*)malloc(sizeof(char)*MaxLen);
        title[i]=(char*)malloc(sizeof(char)*MaxLen);

        printf("Author %d: \n", i+1);
        scanf("%s", author[i]);

        printf("Title %d: \n", i+1);
        scanf("%s", title[i]);

        printf("Year %d: \n", i+1);
        scanf("%d", &year[i]);
    }

    ///a)
    bool isSorted;
    do
    {
        isSorted=true;
        for (int i=0; i<n-1; i++)
        {
            if (strcmp(author[i], author[i+1])>0)
            {
                isSorted=false;
                swap(author[i], author[i+1]);
            }
        }
    }while (!isSorted);

    printf("Authors in alphabetical order:\n");
    for (int i=0; i<n; i++)
    {
        printf("%s ", author[i]);
    }
    printf("\n");


    ///b)
    do
    {
        isSorted=true;
        for (int i=0; i<n-1; i++)
        {
            if (year[i]>year[i+1])
            {
                isSorted=false;
                int aux=year[i];
                year[i]=year[i+1];
                year[i+1]=aux;

                swap(author[i], author[i+1]);
                swap(title[i], title[i+1]);
            }
        }
    }while (!isSorted);

    printf("Books in order of the publication year:\n");
    for (int i=0; i<n; i++)
    {
        printf("%s %s %d\n", author[i], title[i], year[i]);
    }

    return 0;
}
