#include "lorry.h"



void initialize(lorry *cargo,int n)
{
    for(int i=0; i<n; i++)
    {
        cargo[i].material=(char*)malloc(sizeof(char)*100);
    }
}
void readCargo(lorry *cargo,int n)
{
    for(int i=0; i<n; i++)
    {
        getchar();
        printf("Enter material: ");
        gets(cargo[i].material);


        printf("Enter price per kilogram: ");
        scanf("%d",&cargo[i].price);

        printf("Enter number of kilograms: ");
        scanf("%d",&cargo[i].kilos);
        printf("\n");
    }
}
void sortLoad(lorry *cargo,int n)
{
    lorry aux;


        for(int i=0; i<n; i++)
        {
            if(cargo[i].price<cargo[i+1].price)
            {
                aux=cargo[i];
                cargo[i]=cargo[i+1];
                cargo[i+1]=aux;
            }

        }


}
int maxLoad(lorry *cargo,int n,int kg)
{
    int load=0;
    int i=0;
    while(kg>0 && i<n)
    {
        if(kg<=cargo[i].kilos)
        {
            load=load+kg*cargo[i].price;
            kg=0;
        }
        else
        {
            kg=kg-cargo[i].kilos;
            load=load+cargo[i].price*cargo[i].kilos;
        }
        i++;
    }
    return load;
}
