#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    char author[26];
    char title[26];
    int year;
};

void alphabeticOrderByAuthor (struct book list[55], int n)
{
    struct book aux;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp (list[i].author, list[j].author) > 0)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }
}

void orderByYear (struct book list[55], int n)
{
    int i, j;
    struct book aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (list[i].year > list[j].year)
            {
                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
        }
    }

}

int main ()
{
    struct book list[55];
    int n, i;
    printf ("n = ");
    scanf ("%d", &n);
    getchar ();
    for (i = 0; i < n; i++)
    {
        printf ("author book#%d: ", i);
        scanf ("%[^\n]", list[i].author);
        getchar ();
        printf ("title book#%d: ", i);
        scanf ("%[^\n]", list[i].title);
        getchar ();
        printf ("year of publication of book#%d: ", i);
        scanf ("%d", &list[i].year);
        getchar ();
    }

    alphabeticOrderByAuthor (list, n);

    printf ("*********************\nThe authors in alphabetic order are:\n");
    for (i = 0; i < n; i++)
    {
        printf ("%s\n", list[i].author);
    }

    orderByYear (list, n);

    printf ("*********************\nThe order of the publication year is:\n");

    for (i = 0; i < n; i++)
    {
        printf ("%s - %s (%d)\n", list[i].author, list[i].title, list[i].year);
    }

    return 0;
}
