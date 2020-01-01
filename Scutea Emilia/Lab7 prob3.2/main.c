#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int n;
    printf("Please insert the size of the matrices:");
    scanf("%d",&n);
    int ** a=readMatrix(n);
    int ** b=readMatrix(n);
    int ** multiplicationMatrix=multiplicateMatrix(a,b,n);
    printf("The first matrix is:\n");
    printMatrix(a,n);
    printf("The second matrix is:\n");
    printMatrix(b,n);
    printf("The matrix of multiplication is:\n");
    printMatrix(multiplicationMatrix,n);
}
