/**Read from the standard input the names of n kings and the corresponding year limits of their state leading periods. Display:
- the list of kings as they were read
- a list of kings in alphabetic order, completed with the number of years they ruled.
- A list kings in the ascending order of their ruling time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct kings {

    char name[100];
    int startYear, endYear;

}vect[100], aux;

void read(int n) {

    for(int i = 0; i < n; i++) {

        printf("Read the king's name: ");
        gets(vect[i].name);
        printf("Enter the ruling time: ");
        scanf("%d %d", &vect[i].startYear, &vect[i].endYear);
        getchar();
        printf("\n");
    }

}

void write(int n) {

    for(int i = 0; i < n; i++) {
        puts(vect[i].name);
    }

}

void ascendingRuling(int n) {

    bool done = false;

    while(!done) {

        done = true;

        for(int i = 0; i < n - 1; i++) {

            if(vect[i].startYear > vect[i + 1].endYear) {

                done = false;
                aux = vect[i];
                vect[i] = vect[i + 1];
                vect[i + 1] = aux;

            }
        }
    }

}

void alphabetic(int n) {

    bool done = false;

    while(!done) {

        done = true;

        for(int i = 0; i < n - 1; i++) {
            if(stricmp(vect[i].name, vect[i + 1].name) > 0) {

                done = false;
                aux = vect[i];
                vect[i] = vect[i+1];
                vect[i + 1] = aux;

            }
        }
    }

}

void writeAlphabetic(int n) {

    printf("\nThe list of kings in alphabetic order is: \n");

    for(int i = 0; i < n; i++) {

        printf("Name: %s\nNo. of years: %d\n", vect[i].name, vect[i].endYear - vect[i].startYear);

    }

}

int main() {

    int n;
    printf("Read the value of n: ");
    scanf("%d", &n);
    getchar();

    read(n);
    write(n);

    alphabetic(n);
    writeAlphabetic(n);

    ascendingRuling(n);
    printf("\nThe list of kings in the ascending order of their ruling time is: \n");
    write(n);
    return 0;

}
