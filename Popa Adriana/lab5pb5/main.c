#include <stdio.h>
#include <stdlib.h>

void print(int rows,int cols,int** matB)
{
    int i,j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
            printf("%d ",matB[i][j]);
        printf("\n");
    }
}

void addition(int** matB,int** matC,int** matA,int rows,int cols)
{
    int i,j;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            matA[i][j]=matB[i][j]+matC[i][j];
}

void subtraction(int** matB,int** matC,int** matA,int rows,int cols)
{
    int i,j;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            matA[i][j]=matB[i][j]-matC[i][j];
}

void multiplication(int** matB,int** matC,int** matA,int rows,int cols)
{
    int i,j,k;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            matA[i][j]=0;
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            for(k=0; k<rows; k++)
                matA[i][j]=matA[i][j]+matB[k][j]*matC[k][j];
}

void calculus(int** matB,int** matC,int** matA,int rows,int cols)
{
    int i,j;
    int** matD=(int**)(malloc(sizeof(int*)*rows));
    for(i=0; i<rows; i++)
        matD[i]=(int*)(malloc(sizeof(int*)*cols));
     addition(matB,matC,matD,rows,cols);
     multiplication(matB,matC,matA,rows,cols);
      for(i=0; i<rows; i++)
         for(j=0; j<cols; j++)
            matA[i][j]=matA[i][j]-2*matD[i][j];
}

int main()
{
    int rows,cols,i,j;
    printf("rows=");
    scanf("%d",&rows);
    printf("cols=");
    scanf("%d",&cols);

    int** matB=(int**)(malloc(sizeof(int*)*rows));
    for(i=0; i<rows; i++)
        matB[i]=(int*)(malloc(sizeof(int*)*cols));
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&matB[i][j]);
        }
    print(rows,cols,matB);

    int** matC=(int**)(malloc(sizeof(int*)*rows));
    for(i=0; i<rows; i++)
        matC[i]=(int*)(malloc(sizeof(int*)*cols));
    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
        {
            printf("mat[%d][%d]=",i,j);
            scanf("%d",&matC[i][j]);
        }
    print(rows,cols,matC);

    int** matA=(int**)(malloc(sizeof(int*)*rows));
    for(i=0; i<rows; i++)
        matA[i]=(int*)(malloc(sizeof(int*)*cols));

    addition(matB,matC,matA,rows,cols);
    printf("the addition of the matrix is:\n");
    print(rows,cols,matA);
    subtraction(matB,matC,matA,rows,cols);
    printf("the subtraction of the matrix is:\n");
    print(rows,cols,matA);
    multiplication(matB,matC,matA,rows,cols);
    printf("the multiplication of the matrix is:\n");
    print(rows,cols,matA);
    calculus(matB,matC,matA,rows,cols);
    printf("A=B*C-2*(B+C)=\n");
    print(rows,cols,matA);
    return 0;
}
