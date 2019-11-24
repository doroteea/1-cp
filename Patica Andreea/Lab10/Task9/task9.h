#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *name;
    int amount;
    int price;
}materials;

materials *readMaterial(int n);
void sort (materials *material, int n);
void calculateValue (materials *material, int n, int m, int *totalValue, int *nrOfMaterials);
void printMaterial (materials *material, int nrOfMaterials, int totalValue);
