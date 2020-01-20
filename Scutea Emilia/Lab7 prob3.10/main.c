#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int rows,columns;
    printf("Pleaase insert the number of rows:");
    scanf("%d",&rows);
    printf("Pleaase insert the number of columns:");
    scanf("%d",&columns);
    int ** matrix=readMatrix(rows,columns);
    printf("The matrix is:\n");
    printMatrix(matrix,rows,columns);
    int ** transposedMatrix=transposedOfMatrix(matrix,rows,columns);
    printf("The transposed of the matrix is:\n");
    printMatrix(transposedMatrix,columns,rows);
}
