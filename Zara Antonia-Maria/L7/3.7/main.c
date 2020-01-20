#include <stdio.h>
#include <stdlib.h>

///functioneaza

int main()
{
    int i,order,derivative,j;

    printf("Input the order of the polynomial: ");
    scanf("%d",&order);
    int *coefficients=(int*)malloc(sizeof(int)*order);

    printf("Input the coefficient for x to the power of:\n");
    for(i=order;i>=0;i--)
    {
        printf("%d -> ",i);
        scanf("%d",&coefficients[i]);
    }

    printf("Input the order of the derivative: ");
    scanf("%d",&derivative);

    if(derivative>order+1)
        for(i=0;i<=order;i++)coefficients[i]=0;
    ///daca se deriveaza de prea multe ori polinomul devine 0

    else
    {
    for(i=1; i<=derivative; i++)
    {
        for(j=0; j<=order; j++)
        {
            coefficients[j]=coefficients[j+1]*(j+1);
        }
        for(j=1;j<=i;j++)
            coefficients[order-j+1]=0;

    }
    }

    for(i=order;i>=0;i--)
        printf("%d*x^%d\n",coefficients[i],i);
    return 0;
}
