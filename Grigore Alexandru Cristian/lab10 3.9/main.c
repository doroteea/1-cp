#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lorry.h"


int main()
{
    int numberOfMaterials,m;
    printf("Enter maximum load of the lorry.\n");
    scanf("%d",&m);
    printf("Maximum load is %d kilos\n",m);
    printf("Enter number of materials: ");
    scanf("%d",&numberOfMaterials);
    printf("Number of materials is %d.\n",numberOfMaterials);

    lorry *cargoLoad=(lorry*)malloc(sizeof(lorry)*numberOfMaterials);
    initialize(cargoLoad,numberOfMaterials);
    readCargo(cargoLoad,numberOfMaterials);
    sortLoad(cargoLoad,numberOfMaterials);
    printf("Maximum value of the load is %d",maxLoad(cargoLoad,numberOfMaterials,m));

    return 0;
}
