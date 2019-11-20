#include <stdio.h>
#include <stdlib.h>

int main()
{
    int order1,order2,i;

    printf("Input the order of the first polynomial: ");
    scanf("%d",&order1);
    int *coefficients1=(int*)malloc(sizeof(int)*order1);
    printf("Input the coefficients of x to the power of: ");
    for(i=0;i<=order1;i++)
    {
        printf("\n %d -> ",i);
        scanf("%d",&coefficients1[i]);
    }

    printf("Input the order of the second polynomial: ");
    scanf("%d",&order2);
    int *coefficients2=(int*)malloc(sizeof(int)*order2);
    printf("Input the coefficients of x to the power of: ");
    for(i=0;i<=order2;i++)
    {
        printf("\n %d -> ",i);
        scanf("%d",&coefficients2[i]);
    }

    ///notez prezenta fiecarei putere din polinom cu 1 intr-un vector
    ///prezenta in vector va fi notata pana la puterea maxima dintre cele doua polinoame
    int orderMax;
    if(order1>order2)orderMax=order1;
                else orderMax=order2;

    int *presenceOfPowerOfX1=(int*)malloc(sizeof(int)*orderMax);
    for(i=0;i<=order1;i++)
        if(coefficients1[i]!=0)presenceOfPowerOfX1[i]=1;
                        else presenceOfPowerOfX1[i]=0;

    int *presenceOfPowerOfX2=(int*)malloc(sizeof(int)*orderMax);
    for(i=0;i<=order2;i++)
        if(coefficients2[i]!=0)presenceOfPowerOfX2[i]=1;
                        else presenceOfPowerOfX2[i]=0;

    ///acum am realizat ca puteam sa fac asta de la inceput dar nu mai schimb

    ///Gradul polinomului final este suma gradelor celor doua polinoame

    int orderFinal;
    orderFinal=order1+order2;

    int *coefficientsFinal=(int*)malloc(sizeof(int)*orderFinal);
    for(i=0;i<=orderFinal;i++)
        coefficientsFinal[i]=0;

    ///incepe in sfarsit inmultirea

    int j;
    for(i=0;i<=order1;i++)
        for(j=0;j<=order2;j++)
    {
        coefficientsFinal[i+j]=coefficientsFinal[i+j]+coefficients1[i]*coefficients2[j];
    }

    int *presenceOfPowerOfXFinal=(int*)malloc(sizeof(int)*orderMax);
    for(i=0;i<=orderFinal;i++)
        if(coefficientsFinal[i]!=0)presenceOfPowerOfXFinal[i]=1;
                        else presenceOfPowerOfXFinal[i]=0;

    ///gata acum afisam
    printf("The product of the two polynomials is: \n");
    for(i=orderFinal;i>=0;i--)
        if(presenceOfPowerOfXFinal[i]!=0)
    {
        printf("%d*x^%d\n",coefficientsFinal[i],i);
    }


    return 0;
}
