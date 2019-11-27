#include <stdio.h>
#include <stdlib.h>

const int MAX_PRODUCTS = 100;
const int MAX_LINE_LENGTH = 2000;
const int MAX_LENGTH = 200;


typedef struct {
    int code;
    char * name;
    char * unitOfMeasure;
    int amount;
    float price;
} product;

void initializeProduct(product * prod) {
    prod->name = (char*)malloc(sizeof(char)*MAX_LENGTH);
    prod->unitOfMeasure = (char*)malloc(sizeof(char)*MAX_LENGTH);
}

void printProduct(product prod) {
    printf("Product: %d,%s,%s,%d,%f\n", prod.code, prod.name, prod.unitOfMeasure, prod.amount, prod.price);
}

int main()
{
    FILE * f;
    f = fopen("example_file.txt","r+");
    char * strbuf = (char*) malloc(sizeof(char)*MAX_LENGTH);

    product * products = (product*) malloc(sizeof(product)*MAX_PRODUCTS);
    for(int i=0; i<MAX_PRODUCTS; i++) {
        initializeProduct(&products[i]);
    }

    int pCount = 0;
    while(fgets(strbuf, MAX_LENGTH, f) != NULL) {
        sscanf(strbuf,"%d %s %s %d %f",&products[pCount].code,products[pCount].name,products[pCount].unitOfMeasure,&products[pCount].amount,&products[pCount].price);

        printProduct(products[pCount]);
        pCount++;
    }


    fclose(f);

    return 0;
}
