#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int code;
    char * name;
    char * unitOfMeasure;
    int  amount;
    int price;
}Product;

Product * readProducts(FILE * f,int n)
{
    Product * products=(Product*)malloc(sizeof(Product)*n);
    for(int i=0;i<n;i++)
    {
        fscanf(f,"%d",&products[i].code);
        products[i].name=(char*)malloc(sizeof(char)*30);
        fgets(products[i].name,30,f);
        products[i].unitOfMeasure=(char*)malloc(sizeof(char)*30);
        fgets(products[i].unitOfMeasure,30,f);
        fscanf(f,"%d",&products[i].amount);
        fscanf(f,"%d",&products[i].price);
    }
    return products;
}

void printProducts(Product * products,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d %s %s %d %d \n",products[i].code, products[i].name,products[i].unitOfMeasure,products[i].amount,products[i].price);
    }
}

void sortByCode(Product * products,int n)
{
    FILE * g=fopen("Product.out","w");
    int ok=0;
    Product aux;
    while(ok!=1)
    {
        ok=1;
        for(int i=0;i<n-1;i++)
        {
            if(products[i].code>products[i+1].code)
            {
                aux=products[i];
                products[i]=products[i+1];
                products[i+1]=aux;
                ok=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        fprintf(g,"%d %s %s %d %d \n",products[i].code, products[i].name,products[i].unitOfMeasure,products[i].amount,products[i].price);
    }
    fclose(g);
}
int main()
{
    FILE * f=fopen("Product.in","r");
    int n;
    fscanf(f,"%d",&n);
    Product * products=readProducts(f,n);
    printProducts(products,n);
    sortByCode(products,n);///sorts the product by their code
    fclose(f);
}
