#include <stdio.h>
#include <stdlib.h>

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
    for(i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&mat[i][j]);
            transposed[j][i]=mat[i][j];
        }
    }
    for(i=0; i<cols; i++)
    {
        printf("\n");
        for(int j=0; j<rows; j++)
        {
            printf("%d ",transposed[i][j]);

        }
    }
    return 0;
}
