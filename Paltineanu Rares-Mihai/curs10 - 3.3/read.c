#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    int day;
    int month;
    int year;

}birthday;

typedef struct {

    char *name;
    char *address;
    birthday dateOfBirth;

}student;

void initialize(student *g, int n) {

    for(int i = 0; i < n; i++) {

        g[i].name = (char *)malloc(sizeof(char) * 100);
        g[i].address = (char *)malloc(sizeof(char) * 100);

    }
}

void read(student *g, int n) {


    getchar();

    for(int i = 0; i < n; i++) {

        printf("Please enter the name: ");

        gets(g[i].name);

        printf("Please enter the address: ");
        gets(g[i].address);

        printf("Enter the birthday: \n");
        printf("Please enter the day: ");
        scanf("%d", &g[i].dateOfBirth.day);

        printf("Please enter the month: ");
        scanf("%d", &g[i].dateOfBirth.month);

        printf("Please enter the year: ");
        scanf("%d", &g[i].dateOfBirth.year);
        printf("\n");
        getchar();

    }

}

void write(student *g, int n) {

    for(int i = 0; i < n; i++) {

        printf("Name: %s\nAddress %s\nBirthday %d.%d.%d\n\n", g[i].name, g[i].address,
               g[i].dateOfBirth.day, g[i].dateOfBirth.month, g[i].dateOfBirth.year);
    }
}

void lexicographicSort(student *g, int n) {

    bool done = false;
    student aux;

    while(!done) {

        done = true;

        for(int i = 0; i < n - 1; i++) {

            if(strcmp(g[i].name, g[i + 1].name) > 0) {

                aux = g[i];
                g[i] = g[i + 1];
                g[i + 1] = aux;
                done = false;

            }
        }
    }
}
