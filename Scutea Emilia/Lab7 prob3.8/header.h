#include <stdio.h>
#include <stdlib.h>

int * readPolynomial(int size)
{
    int * array=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<=size;i++)
    {
        printf("Please insert the coefficient of the power %d: ",i);
        scanf("%d",(array+i));
    }
    return array;
}

void printPolynomial(int * array,int size)
{
    for(int i=0;i<=size;i++)
    {
        if(i!=size)
        {
            printf("%d*x^%d + ",*(array+i),i);
        }
        else
        {
            printf("%d*x^%d.",*(array+i),i);
        }

    }
    printf("\n");
}

int * product(int * array1,int * array2,int size1,int size2,int size3)
{
    int * array3=(int*)malloc(sizeof(int)*size3);
    for(int i=0;i<=size1;i++)
    {
        for(int j=0;j<=size2;j++)
        {
            *(array3+i+j) = *(array1+i) * *(array2+j);
        }
    }
    return array3;
}
