#include "task9.h"


void initialize(materials *a)
{
    a->name = (char*)malloc(sizeof(char)*100);
}

materials *readMaterial (int n)
{
    materials *material = (materials*)malloc(sizeof(materials)*n);
    getchar();

    printf("Insert information for each material!\n");
    for (int i=0; i<n; i++)
    {
        initialize (material+i);

        printf("Insert the name for material %d!\n", i+1);
        scanf("%s", material[i].name);

        printf("Insert the quantity of the material %d!\n", i+1);
        scanf("%d", &material[i].amount);

        printf("Insert the price per kilo for the material %d!\n", i+1);
        scanf("%d", &material[i].price);
        printf("\n");
    }

    return material;
}

void swap (materials *a, materials *b)
{
    materials *aux=(materials*)malloc(sizeof(materials));
    *aux=*a;
    *a=*b;
    *b=*aux;
}

void sort (materials *material, int n)
{
    bool isSorted;
    do
    {
        isSorted=true;
        for (int i=0; i<n-1; i++)
        {
            if (material[i].price<material[i+1].price)
            {
                isSorted=false;
                swap(material+i, material+i+1);
            }
        }
    }while (!isSorted);
}

void calculateValue (materials *material, int n, int m, int *totalValue, int *nrOfMaterials)
{
    int i=0;
    while (i<n)
    {
        if (m>=material[i].amount)
        {
            totalValue+=material[i].price*material[i].amount;
            material[i].price*=material[i].amount;
            m-=material[i].amount;
            nrOfMaterials++;
        }
        else
        {
            totalValue+=material[i].price*m;
            material[i].amount=m;
            material[i].price*=material[i].amount;
            m=0;
            nrOfMaterials++;
        }

        if (m==0)
        {
            break;
        }
        i++;
    }
}

void printMaterial (materials *material, int nrOfMaterials, int totalValue)
{
    printf("The maximum value is: %d\n", totalValue);
    printf("The materials are:\n");
    for (int i=0; i<nrOfMaterials; i++)
    {
        printf("%d kilograms of material %s with the value %d\n", material[i].amount, material[i].name, material[i].price);
    }
}
