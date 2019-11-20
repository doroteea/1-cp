#include <stdio.h>
#include <stdlib.h>
void subststraction(int** mat1,int** mat2,int row,int** mat3)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<row;j++)
        {
            mat3[i][j]=mat1[i][j]-mat2[i][j];
        }
}
void additionTimes2(int** mat1,int** mat2,int row,int** mat3)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<row;j++)
        {
            mat3[i][j]=(mat1[i][j]+mat2[i][j])*2;
        }
}
void multiplication(int** mat1,int** mat2,int row,int** mat3)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<row;j++)
        {
            mat3[i][j]=mat1[i][j]*mat2[i][j];
        }
}
int main()
{
    int i,j,rows;
    printf("Numarul de randuri si coloane=");
    scanf("%d",&rows);
    int** A = (int**)malloc(sizeof(int*)* rows);
    int** B=(int**)malloc(sizeof(int*) * rows);
    int** C=(int**)malloc(sizeof(int*) * rows);
    int** D=(int**)malloc(sizeof(int*) * rows);
    int** E=(int**)malloc(sizeof(int*) * rows);
    for(int i=0;i<rows;i++)
    {
        B[i]=(int*)malloc(sizeof(int)*rows);
        C[i]=(int*)malloc(sizeof(int)*rows);
        A[i]=(int*)malloc(sizeof(int)*rows);
        D[i]=(int*)malloc(sizeof(int)*rows);
        E[i]=(int*)malloc(sizeof(int)*rows);
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<rows;j++)
        {
            printf("B[%d][%d]=",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<rows;j++)
        {
            printf("C[%d][%d]=",i,j);
            scanf("%d",&C[i][j]);
        }
    }
    multiplication(B,C,rows,D);
    additionTimes2(B,C,rows,E);
    subststraction(D,E,rows,A);
    for(i=0;i<rows;i++)
    {
        printf("\n");
        for(j=0;j<rows;j++)
        {
            printf("%d ",A[i][j]);
        }
    }
    return 0;
}
