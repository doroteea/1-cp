#include <stdio.h>
#include <stdlib.h>

int ** allocateMatrix(int rows,int columns)
{
    int ** mat=(int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++)
    {
        *(mat+i)=(int*)malloc(sizeof(int)*columns);
    }
    return mat;
}

int ** readMatrix(int rows,int columns)
{
    int ** mat=allocateMatrix(rows,columns);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("Please insert the element on the position %d %d: ",i,j);
            scanf("%d",(*(mat+i)+j));
        }
    }
    return mat;
}

void printMatrix(int ** mat,int rows,int columns)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%d  ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}

int ** transposedOfMatrix(int ** mat,int rows,int columns)
{
    int ** transposedMatrix=allocateMatrix(columns,rows);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            *(*(transposedMatrix+j)+i)= *(*(mat+i)+j);
        }
    }
    return transposedMatrix;
}
