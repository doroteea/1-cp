#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int m;
    printf("Please insert the kilograms value:\nm=");
    scanf("%d",&m);
    int n;
    printf("Please insert the number of materials:\nn=");
    scanf("&d",&n);
    materials *mat=readMaterials(n);
    printMaterials(mat,n);
    priceDescendingOrder(mat,n);
    maximumLoad(mat,n,m);
}
