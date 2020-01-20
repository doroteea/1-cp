#include <stdio.h>
#define line 2
#define col 2


void initZero (int **D)
{
    for (int i=0; i<line; i++)
    {
        for (int j=0; j<col; j++)
        {
            D[i][j]=0;
        }
    }
}

void initMatrix (int **A, int **B)
{
    for (int i=0; i<line; i++)
    {
        for (int j=0; j<col; j++)
        {
            A[i][j]=B[i][j];
        }
    }
}

int** multiplicateMatrix (int **A, int **B)
{
    int **C = (int**)malloc(sizeof(int)*line);
    for (int i=0; i<line; i++)
    {
        C[i]=(int*)malloc(sizeof(int)*col);
    }
    initZero(C);

    for (int i=0; i<line; i++)
        {
            for (int j=0; j<col; j++)
            {
                for (int l=0; l<col; l++)
                {
                    C[i][j]+=(A[i][l]*B[l][j]);
                    printf("%d %d %d\n", C[i][j], A[i][l], B[l][j]);
                }
            }
        }

        printf("\n");
        for (int i=0; i<line; i++)
        {
            for (int j=0; j<col; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }

    return C;

}

int** calculatePower (int **mat, int k)
{
    int **B = (int**)malloc(sizeof(int)*line);
    for (int i=0; i<line; i++)
    {
        B[i]=(int*)malloc(sizeof(int)*col);
    }

    initZero(B);
    initMatrix(B, mat);

    int power=1;
    while (power<k)
    {
        B=multiplicateMatrix(B, mat);
        power++;
    }
        printf("\n");
        for (int i=0; i<line; i++)
        {
            for (int j=0; j<col; j++)
                printf("%d ", B[i][j]);
            printf("\n");
        }

    return B;
}

int main()
{
    int **mat = (int**)malloc(sizeof(int)*line);
    for (int i=0; i<line; i++)
    {
        mat[i]=(int*)malloc(sizeof(int)*col);
    }

    printf("Insert the matrix!\n");
    for (int i=0; i<line; i++)
    {
        for (int j=0; j<col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int k;
    printf("Insert power!\n");
    scanf("%d", &k);

    int **A = (int**)malloc(sizeof(int)*line);
    for (int i=0; i<line; i++)
    {
        A[i]=(int*)malloc(sizeof(int)*col);
    }

    initZero(A);
    A=calculatePower(mat, k);

    for (int i=0; i<line; i++)
    {
        for (int j=0; j<col; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
