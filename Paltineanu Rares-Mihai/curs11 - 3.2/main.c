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

typedef struct {

    char *code;
    char *name;
    char *unit;
    char *amount;
    char *price;

} shop;

void initialize(shop *v, int n) {

    for(int i = 0; i <= n; i++) {

        v[i].code = (char *)malloc(sizeof(char) * 100);
        v[i].name = (char *)malloc(sizeof(char) * 100);
        v[i].unit = (char *)malloc(sizeof(char) * 100);
        v[i].amount = (char *)malloc(sizeof(char) * 100);
        v[i].price = (char *)malloc(sizeof(char) * 100);

    }

}

void read(shop *v, int n, FILE *fil) {

    char *text = (char *)malloc(sizeof(char) * 100);
    char *tok;
    for(int i = 0; i < n; i++) {

        fgets(text, 100, fil);
        puts(text);

        tok = strtok(text, " ");
        strcpy(v[i].code, tok);
        puts(v[i].code);

        tok = strtok(NULL, " ");
        strcpy(v[i].name, tok);
         puts(tok);

        tok = strtok(NULL, " ");
        strcpy(v[i].unit, tok);
        puts(tok);

        tok = strtok(NULL, " ");
        strcpy(v[i].amount, tok);
        puts(tok);

        tok = strtok(NULL, " ");
        strcpy(v[i].price, tok);
        puts(tok);
    }

}


void write(shop *v, int n) {

    for(int i = 0; i < n; i++) {

        printf("%s, %s, %s, %s, %s\n\n\n", v[i].code, v[i].name, v[i].amount, v[i].unit, v[i].price);

    }

}

int main() {

    FILE *fil;
    fil = fopen("32.txt", "r");

    int n;
    fscanf(fil, "%d", &n);

    //printf("%d\n\n", n);
    shop *vect = (shop *)malloc((sizeof(shop) * n));

    initialize(vect, n);

    read(vect, n, fil);
    write(vect, n);

    fclose(fil);

    return 0;
}
