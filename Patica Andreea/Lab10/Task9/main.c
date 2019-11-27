#include "task9.h"

int main()
{
    int m;
    printf("Insert the maximum kilograms that the lorry can carry!\n");
    scanf("%d", &m);
    int n;
    printf("Insert the number of materials!\n");
    scanf("%d", &n);


    materials *material = readMaterial(n);
    sort(material, n);
    int totalValue=0, nrOfMaterials=0;
    calculateValue(material, n, m, &totalValue, &nrOfMaterials);
    printMaterial(material, nrOfMaterials, totalValue);
    return 0;
}
