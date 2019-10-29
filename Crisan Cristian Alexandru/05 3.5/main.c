#include <stdio.h>
#include <stdlib.h>
/*3.5. Write the functions for addition, subtraction and multiplication
of two matrices, and then compute
A = B * C –2*( B + C ),
where B  and C are two quadratic matrices of order n .
*/
void MatrixDisplay(int **Matrix,int MatrixOrder)
{
    for(int i=0; i<MatrixOrder; i++)
    {
        for(int j=0; j<MatrixOrder; j++)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
}
void MatrixRead(int **Matrix,int MatrixOrder)
{
    for(int i=0; i<MatrixOrder; i++)
    {
        for(int j=0; j<MatrixOrder; j++)
        {
            scanf("%d",&Matrix[i][j]);

        }
    }
}
void TwoMatricesAddition(int **MatrixOne,int **MatrixTwo,int **ResultMatrix,int MatrixOrder)
{
    for(int i=0; i<MatrixOrder; i++)
        for(int j=0; j<MatrixOrder; j++)
            ResultMatrix[i][j]=MatrixOne[i][j]+MatrixTwo[i][j];
}
/*void MatrixDeclaration(int ***Matrix,int MatrixOrder)
{
    *Matrix=(int**)malloc(sizeof(int*)*MatrixOrder);
    for(int i=0; i<MatrixOrder; i++)
    {
        *Matrix[i]=(int*)malloc(sizeof(int)*MatrixOrder);
    }
}*/
void TwoMatricesSutraction(int **MatrixOne,int **MatrixTwo,int **ResultMatrix,int MatrixOrder)
{

    for(int i=0; i<MatrixOrder; i++)
        for(int j=0; j<MatrixOrder; j++)
            ResultMatrix[i][j]=MatrixOne[i][j]-MatrixTwo[i][j];

}
void TwoMatricesMultiplication(int **MatrixOne,int **MatrixTwo,int **ResultMatrix,int MatrixOrder)
{
    for(int k=0; k<MatrixOrder; k++)
    {
        for(int j=0; j<MatrixOrder; j++)
        {
            ResultMatrix[k][j]=0;
            for(int i=0; i<MatrixOrder; i++)
            {
                ResultMatrix[k][j]=ResultMatrix[k][j]+MatrixOne[k][j]*MatrixTwo[j][i];
            }
        }
    }
}
void MultiplicationMatrixWithScalar(int **Matrix,int Scalar,int **ResultMatrix,int MatrixOrder)
{
    for(int i=0; i<MatrixOrder; i++)
    {
        for(int j=0; j<MatrixOrder; j++)
        {
            ResultMatrix[i][j]=Matrix[i][j]*Scalar;
        }
    }

}
int main()
{
    int MatrixOrder;
    printf("Give the order of the matrices:");
    scanf("%d",&MatrixOrder);
    int **MultiplicatedMatrix=(int**)malloc(sizeof(int*)*MatrixOrder);
    int **B=(int**)malloc(sizeof(int*)*MatrixOrder);
    int **C=(int**)malloc(sizeof(int*)*MatrixOrder);
    int **A=(int**)malloc(sizeof(int*)*MatrixOrder);
    int **AdditionMatrix=(int**)malloc(sizeof(int*)*MatrixOrder);
    int **ScalarMultipicatedMatrix=(int**)malloc(sizeof(int*)*MatrixOrder);


    for(int i=0; i<MatrixOrder; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*MatrixOrder);
        C[i]=(int*)malloc(sizeof(int)*MatrixOrder);
        MultiplicatedMatrix[i]=(int*)malloc(sizeof(int)*MatrixOrder);
        A[i]=(int*)malloc(sizeof(int)*MatrixOrder);
        AdditionMatrix[i]=(int*)malloc(sizeof(int)*MatrixOrder);
        ScalarMultipicatedMatrix[i]=(int*)malloc(sizeof(int)*MatrixOrder);


    }

    printf("Read the first matrix");
    MatrixRead(B,MatrixOrder);
    printf("Read the second matrix");
    MatrixRead(C,MatrixOrder);
    TwoMatricesMultiplication(B,C,MultiplicatedMatrix,MatrixOrder);
    MatrixDisplay(MultiplicatedMatrix,MatrixOrder);
    TwoMatricesAddition(B,C,AdditionMatrix,MatrixOrder);
    MultiplicationMatrixWithScalar(AdditionMatrix,2,ScalarMultipicatedMatrix,MatrixOrder);
    TwoMatricesSutraction(MultiplicatedMatrix,ScalarMultipicatedMatrix,A,MatrixOrder);

    MatrixDisplay(A,MatrixOrder);

    return 0;
}
