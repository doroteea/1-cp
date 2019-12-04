#include "head.h"


materials *readMaterials(int n)
{
    materials *mat=(materials*)malloc(sizeof(materials)*30);
    for(int i=0; i<n; i++)
    {
        getchar();
        printf("Please insert the name of the material:\n");
        gets(mat[i].material);
        printf("Please insert the amount in kilograms:\n");
        scanf("%d",&mat[i].amount);
        printf("Please insert the price per kilogram:\n");
        scanf("&d",&mat[i].price);
    }
    return mat;

}

void printMaterials(materials *mat,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%s %d %d \n",mat[i].material,mat[i].amount,mat[i].price);
    }
}

materials priceDescendingOrder(materials *mat,int n)
{
    materials *aux=(materials*)malloc(sizeof(materials)*30);
    int ok=0;
    while(ok==0)
    {
        ok=1;
        for(int i=0; i<n-1; i++)
        {
            if(mat[i].price<mat[i+1].price)
            {
                aux[i]=mat[i];
                mat[i]=mat[i+1];
                mat[i+1]=aux[i];
                ok=0;
            }
        }
    }
}

void maximumLoad(materials *mat,int n,int m)
{
    int load=0;
    int value=0;
    for(int i=0;i<n && load<m;i++)
    {
        int k=mat[i].amount;
        int count=0;
        while(load<m &&k!=0)
        {
            if(load+1<m)
            {
                k--;
                count++;
                load++;

            }
        }
        if(load==m)
        {
            i=n;
        }
        printf("%d kilograms of %s",count,mat[i].material);
        value=value+count*mat[i].price;
    }
    printf("The maximum value of the load is %d",value);
}
