#include <stdio.h>
#include <stdlib.h>
int *pol1,*pol2,*prod;
int degree1,degree2;

void readPol(int *pol1, int degree1)
{
    if (degree1>=0)
    {
        printf("Input the coefficients of the polynomial from 0 to degree:\n");
        for(int i=0; i<=degree1; i++)
        {
            scanf("%d",&pol1[i]);
        }
    }
    else
        printf("Degree must be positive");
}
void multiplyPol(int *pol1, int *pol2, int *prod, int degree1, int degree2)
{
    for(int i=0; i<=degree1+degree2; i++)
    {
        prod[i]=0;
    }
    for(int i=0; i<=degree1; i++)
    {
        for(int j=0; j<=degree2; j++)
        {
            prod[i+j]=prod[i+j]+pol1[i]*pol2[j];
        }
    }

}
void printPol(int *prod, int degree1, int degree2)
{
    for(int i=0; i<=degree1+degree2; i++)
    {
        printf("%d",prod[i]);
        if(i!=0)
        {
            printf("x^");
            printf("%d",i);
        }
        if(i!=degree1+degree2)
        {
            printf("+");
        }
    }
}
int main()
{
    printf("Enter the degrees of the polynomials:\n");
    scanf("%d",&degree1);
    scanf("%d",&degree2);
    int *pol1=(int*)malloc(sizeof(int)*degree1);
    int *pol2=(int*)malloc(sizeof(int)*degree2);
    int *prod=(int*)malloc(sizeof(int)*(degree1+degree2-1));
    readPol(pol1,degree1);
    readPol(pol2,degree2);
    multiplyPol(pol1,pol2,prod,degree1,degree2);
    printPol(prod,degree1,degree2);

    return 0;
}
