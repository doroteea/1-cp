#include <stdio.h>
#include <stdlib.h>
void transposedMatrix(int mat1[6][6], int mat2[6][6],int row, int col)
{
    int i;
    for(i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&mat1[i][j]);
            mat2[j][i]=mat1[i][j];
        }
    }
    for(i=0; i<col; i++)
    {
        printf("\n");
        for(int j=0; j<row; j++)
        {
            printf("%d ",mat2[i][j]);

        }
    }
}
int main()
{
    int i,rows,cols;
    printf("Nr of rows= ");
    scanf("%d",&rows);
    printf("\n Nr of columns= ");
    scanf("%d",&cols);
    int** mat=(int**)malloc(sizeof(int*)*rows);
    for(i=0; i<rows; i++)
    {
        mat[i]=(int*)malloc(sizeof(int)*cols);
    }
    int** transposed=(int**)malloc(sizeof(int*)*cols);
    for(i=0; i<cols; i++)
    {
        transposed[i]=(int*)malloc(sizeof(int)*rows);
    }
    transposedMatrix(mat,transposed,rows,cols);


    return 0;
}
