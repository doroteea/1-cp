#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *material[30];
    int amount;
    int price;
} materials;

materials *readMaterials(int n);

void printMaterials(materials *mat,int n);

materials priceDescendingOrder(materials *mat,int n);

void maximumLoad(materials *mat,int n,int m);
