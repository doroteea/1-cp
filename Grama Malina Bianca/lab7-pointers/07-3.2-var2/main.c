#include <stdio.h>
#include <stdlib.h>

int **allocateSquareMatrix (int n)
{
    int **matrix=(int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        *(matrix + i) = (int *) malloc(sizeof(int) * n);
    }
    return matrix;
}

int **readSquareMatrix(int n) {

    int **matrix= allocateSquareMatrix(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            scanf("%d", (*(matrix + i) + j));
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int **multiplyMatrices(int **matrix1, int **matrix2, int n) {

    int **product = allocateSquareMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            *(*(product + i) + j) = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                *(*(product + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }

    return product;
}

int main() {
    int n; //number of lines and columns in the two matrices
    printf("Please insert number of lines/columns for the square matrix: ");
    scanf("%d", &n);

    printf("Please insert values for the first matrix: \n");
    int **mat1 = readSquareMatrix(n);
    printf("The first matrix is: \n");
    printMatrix(mat1, n);

    printf("Please insert values for the second matrix: \n");
    int **mat2 = readSquareMatrix(n);
    printf("The second matrix is: \n");
    printMatrix(mat2, n);

    int **product = multiplyMatrices(mat1, mat2, n);

    printf("The two matrices multiplied are: \n");
    printMatrix(product, n);

    return 0;
}