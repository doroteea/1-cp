/** Read  from  the standard input the  author,  the  title  and  the  publication  year  for  a  number  of n books.
Display the following:
a)the names of the authors in alphabetic order;
b)the names of the authors and the titles of their books in order of the publication year.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct probl {

    char author[200];
    char title[200];
    int year;

}x[200], aux;

void read(int n) {

    for(int i = 0; i < n; i++) {

        printf("Read the author: "); gets(x[i].author);
        printf("Read the title: "); gets(x[i].title);
        printf("Read the year: "); scanf("%d", &x[i].year);
        getchar();
        printf("\n");

    }
}

void alphabeticOrder(int n) {


    bool gata = false;

    while(!gata) {

        gata = true;

        for(int i = 0; i < n - 1; i++) {
            if(strcmp(x[i].author, x[i + 1].author) > 0) {

                gata = false;
                aux = x[i];
                x[i] = x[i + 1];
                x[i + 1] = aux;

            }
        }
    }
}

void publicationYear(int n) {

    bool gata = false;

    while(!gata) {

        gata = true;

        for(int i = 0; i < n - 1; i++) {
            if(x[i].year > x[i + 1].year) {

                gata = false;
                aux = x[i];
                x[i] = x[i + 1];
                x[i + 1] = aux;

            }
        }
    }
}

void writeAuthors(int n) {

    for(int i = 0; i < n; i++) {

        puts(x[i].author);

    }

    printf("\n");

}

void writeAuthorsAndTitles(int n) {

    for(int i = 0; i < n; i++) {

        printf("Author: "); puts(x[i].author);
        printf("Title: "); puts(x[i].title);
        printf("\n");

    }
}

int main() {

    int n;
    printf("Read the value of n: "); scanf("%d", &n);
    getchar();
    read(n);

    alphabeticOrder(n);

    writeAuthors(n);

    publicationYear(n);

    writeAuthorsAndTitles(n);
    return 0;

}
