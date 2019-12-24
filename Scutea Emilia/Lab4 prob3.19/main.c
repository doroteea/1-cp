#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please insert the number of rows and columns:\nn=");
    scanf("%d",&n);
    int **mat=readMatrix(n);
    printMatrix(mat,n);
    if(verifySymmetry(mat,n)==1)
    {
        printf("The matrix is symmetric.");
    }
    else
    {
        printf("The matrix is not symmetric.");
    }
}
