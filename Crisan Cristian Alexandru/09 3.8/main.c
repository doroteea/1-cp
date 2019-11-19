#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*3.8. Read from the standard input the author, the title and the publication year for a number of
n books. Display the following:
a) the names of the authors in alphabetic order;
b) the names of the authors
and the titles of their books in order of the publication year.*/
int NrOfElements;
typedef struct book
{
    char author[20];
    char title[50];
    int year;
} Book;

void AscendingSortByAuthorANDTitle(Book *Array)
{

    Book aux;
    for(int i=0; i<NrOfElements-1; i++)
    {
        for(int j=i+1; j<NrOfElements; j++)
        {

            if(strcmp(Array[i].author,Array[j].author)==1)
            {
                aux=Array[i];
                Array[i]=Array[j];
                Array[j]=aux;
            }

            else
            {
                if(strcmp(Array[i].author,Array[j].author)==0)
                {

                    if(strcmp(Array[i].title,Array[j].title)==1)

                    {
                        aux=Array[i];
                        Array[i]=Array[j];
                        Array[j]=aux;
                    }
                }
            }
        }
    }

}
void DisplayAuthorsAscending(Book *Array)
{
    char CurrentlyDisplaying[20];
    strcpy(CurrentlyDisplaying,Array[0].author);
    printf("%s\n",CurrentlyDisplaying);
    for(int i=1; i<NrOfElements; i++)
    {
        if(strcmp(Array[i].author,CurrentlyDisplaying)!=0)
        {
            printf("%s\n",Array[i].author);
            strcpy(CurrentlyDisplaying,Array[i].author);
        }
    }

}
void Display(Book *Array)
{
    for(int i=0; i<NrOfElements; i++)
    {
        printf("%s de %s publicata in anul %d\n",Array[i].title,Array[i].author,Array[i].year);
    }
}
void AscendingSortByPublicationDate(Book *Array)
{

    Book aux;
    for(int i=0; i<NrOfElements-1; i++)
    {
        for(int j=i+1; j<NrOfElements; j++)
        {
            if(Array[i].year>Array[j].year)
            {
                aux=Array[i];
                Array[i]=Array[j];
                Array[j]=aux;
            }
        }
    }

}
int main()
{
    int choice;
    printf("Give the number of books:");
    scanf("%d",&NrOfElements);
    Book *ArrayOfBooks=(Book*)malloc(sizeof(Book)*NrOfElements);
    for(int i=0; i<NrOfElements; i++)
    {
        printf("Give the title of the book %d :",i+1);
        scanf("%s",&ArrayOfBooks[i].title);
        // gets(ArrayOfBooks[i].title);
        printf("Who's the author?");
        scanf("%s",&ArrayOfBooks[i].author);
        printf("When has the book been published?(year only)");
        scanf("%d",&ArrayOfBooks[i].year);
    }
    printf("1.The names of the authors in alphabetic order.\n2.Authors and the titles of their books in order of the publication year.\n3.Exit\nWhich task do you want to be performed?");
    scanf("%d",&choice);
    while(choice!=3)
    {
        switch(choice)
        {
        case 1:
        {
            AscendingSortByAuthorANDTitle(ArrayOfBooks);
            printf("Authors in ascending order:\n");
            DisplayAuthorsAscending(ArrayOfBooks);
            break;
        }
        case 2:
        {
            AscendingSortByPublicationDate(ArrayOfBooks);
            Display(ArrayOfBooks);
            break;
        }
        default:
        {
            printf("Invalid choice!");
            break;
        }
        }
    printf("1.The names of the authors in alphabetic order.\n2.Authors and the titles of their books in order of the publication year.\n3.Exit\nWhich task do you want to be performed?");
    scanf("%d",&choice);
    }




    return 0;
}
