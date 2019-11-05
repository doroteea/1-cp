#include <stdio.h>
#include <stdlib.h>


///se blocheaza dupa citirea matricei si mor

int ** readMatrix(int n)
{
    int i,rows;
    rows=n;
    int **mat= (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        mat[i]= (int*)malloc(sizeof(int)*rows);
    }
    int r,c;
    printf("Input matrix: \n");
    for(r=0; r<rows; r++)
        for(c=0; c<rows; c++)
        {
            scanf("%d",&mat[r][c]);
        }
    return mat;
}


int ** multiplyMatrix(int **mat1, int **mat2,int rows)
{
    int i,j,k;
    int **productMatrix= (int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        productMatrix[i]= (int*)malloc(sizeof(int)*rows);
    }

    for(i=0;i<rows;i++)
        for(j=0;j<rows;j++)
            productMatrix[i][j]=0;

    for(i=0;i<rows;i++)
        for(j=0;j<rows;j++)
    {
        for(k=0;k<rows;k++)
            productMatrix[i][j]=productMatrix[i][j]+mat1[i][k]*mat2[k][j];
    }

    return productMatrix;

}

void printMatrix(int **mat,int rows)
{
    int i,j;
    for(i=0;i<rows;i++)
        {
            for(j=0;j<rows;j++)
                printf("%d ",mat[i][j]);
            printf("\n");
        }
}

int main()
{
    int **matrix,rows,power;
    printf("Input the number of rows of the matrix: ");
    scanf("%d",&rows);
    printf("\nInput the power wanted: ");
    scanf("%d",&power);
    matrix = readMatrix(rows);

    if(power==1)printMatrix(matrix,rows);
    else
    {
        int i;
        int **growingMatrix= (int**)malloc(sizeof(int*)*rows);
        ///growingMatrix e matricea pe care o tot inmultesc ca sa ajung la putere

        for(i=0; i<rows; i++)
            {
                growingMatrix[i]= (int*)malloc(sizeof(int)*rows);
            }

        growingMatrix = multiplyMatrix(matrix,matrix,power);
        for(i=2;i<power;i++)
        {
            growingMatrix = multiplyMatrix(growingMatrix,matrix,power);
            /// <=> growingMatrix = growingMatrix*matrix;
        }

        printMatrix(growingMatrix,rows);
    }

    return 0;
}
