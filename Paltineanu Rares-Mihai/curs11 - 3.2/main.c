/**
Create a file containing a list of items a shop sells.
An item is represented as a structure which contains:
-a code;
-a name;
-a unit of measure;
-the amount;
-price per unit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    char* code;
    char* name;
    char* unit;
    char* amount;
    char* price;

} shop;

void initialize(shop* v, int n) {

    for(int i = 0; i <= n; i++) {

        v[i].code = (char *)malloc(sizeof(char) * 100);
        v[i].name = (char *)malloc(sizeof(char) * 100);
        v[i].unit = (char *)malloc(sizeof(char) * 100);
        v[i].amount = (char *)malloc(sizeof(char) * 100);
        v[i].price = (char *)malloc(sizeof(char) * 100);

    }

}

void read(shop* v, int* n, FILE* fil) {

    char* text = (char *)malloc(sizeof(char) * 100);
    char* tok;
    while(fgets(text, 100, fil) != NULL) {

        tok = strtok(text, " ");
        strcpy(v[*n].code, tok);

        tok = strtok(NULL, " ");
        strcpy(v[*n].name, tok);

        tok = strtok(NULL, " ");
        strcpy(v[*n].unit, tok);

        tok = strtok(NULL, " ");
        strcpy(v[*n].amount, tok);

        tok = strtok(NULL, " ");
        strcpy(v[*n].price, tok);

        (*n)++;

    }

}


void write(shop* v, int n) {

    for(int i = 0; i < n; i++) {

        printf("code:%s, name:%s, amount:%s, unit:%s, price:%s\n", v[i].code, v[i].name, v[i].amount, v[i].unit, v[i].price);

    }

}

void sort(shop *v, int n) {

    shop aux;

    bool done = false;

    while(!done) {

        done = true;

        for(int i = 0 ; i < n - 1; i++) {

            if(strcmp(v[i].code, v[i + 1].code) > 0) {

                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                done = false;


            }
        }
    }
}

void writeInFile(shop* v, int n, FILE *write) {

    for(int i = 0; i < n; i++) {

        fprintf(write, "code:%s, name:%s, amount:%s, unit:%s, price:%s\n", v[i].code, v[i].name, v[i].amount, v[i].unit, v[i].price);

    }

}
int main() {

    FILE *fil1;
    fil1 = fopen("32.txt", "r");

    if(fil1 == NULL) {

        return -1;

    }

    int n = 0;

    shop *vect = (shop *)malloc((sizeof(shop) * 1000));

    initialize(vect, 1000);

    read(vect, &n, fil1);

    realloc(vect, sizeof(shop) * (n ));
    write(vect, n);

    ///3.3

    FILE *fil2;
    fil2 = fopen("33.txt", "w");

    if(fil2 == NULL) {

        return -2;

    }

    sort(vect, n);
    writeInFile(vect, n, fil2);

    fclose(fil1);
    fclose(fil2);

    return 0;
}
