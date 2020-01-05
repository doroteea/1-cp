/** 3.9.A lorry can carry at most m kilograms. The name of the materials,
        the amounts in kilograms, and the price per kilo are known.
        Find a load composition such a way the value of the load is maximum.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float amount;
    char *name;
    float price;
} materialType;

materialType *readMaterials(int number)
{
    materialType *materials = (materialType*)malloc(sizeof(materialType)*10);
    int i;
    for(i=0; i<10; i++)
    {
        materials[i].name = (char*)malloc(sizeof(char)*25);
    }

    for(i=0; i<number; i++)
    {
        printf("Input the name of material number %d: ",i+1);
        scanf("%s",materials[i].name);

        printf("Input the amount of %s we have: ",materials[i].name);
        scanf("%f",&materials[i].amount);

        printf("Input the price of %s per kg: ",materials[i].name);
        scanf("%f",&materials[i].price);
    }

    return materials;
}

materialType *sortMaterials(int number, materialType *materials)
{
    materialType *aux = (materialType*)malloc(sizeof(materialType));
    int i;
    for(i=0; i<10; i++)
    {
        aux[i].name = (char*)malloc(sizeof(char)*25);
    }

    int j;
    for(i=0; i<number - 1; i++)
        for(j=i; j<number; j++)
        {
            if(materials[i].price < materials[j].price)
            {
                *aux = materials[i];
                materials[i] = materials[j];
                materials[j] = *aux;
            }
        }

    return materials;
}

void putInLorry(materialType *materials, int number, float max)
{
    float amountIn = 0;
    float priceIn = 0;
    int i;

    i = 0;
    while(amountIn < max && i < number)
    {
        if(materials[i].amount <= max - amountIn)
        {
            amountIn = amountIn + materials[i].amount;
            priceIn = priceIn + materials[i].amount * materials[i].price;
            i++;
        }
        else
        {
            priceIn = priceIn + materials[i].price * (max - amountIn);
            amountIn = max;
            break;
        }
    }

    printf("\nThe maximum price of the lorry is: %f\n",priceIn);
}

int main()
{
    materialType *materials = (materialType*)malloc(sizeof(materialType)*10);
    int i;
    for(i=0; i<10; i++)
    {
        materials[i].name = (char*)malloc(sizeof(char)*25);
    }

    float max;
    printf("Input maximum amount the lorry can carry: ");
    scanf("%f",&max);

    int number;
    printf("Input the number of materials: ");
    scanf("%d",&number);

    materials = readMaterials(number);

    materials = sortMaterials(number,materials);

    putInLorry(materials,number,max);

    return 0;
}
