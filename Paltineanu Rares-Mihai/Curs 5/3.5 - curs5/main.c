/**
Write the functions for addition, subtraction and multiplication of two matrices,
and then compute A=B*C–2*(B+C), where BandCare two quadratic matrices of order n.
*/
#include <stdio.h>
#include <stdlib.h>
/// 1 2 3   1 2 3
/// 1 2 3   1 2 3
/// 1 2 3   1 2 3
int n;

void readMat(int **B) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

}

void writeMat(int **B) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
}

void addition(int **B, int **C, int **newD) {

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            newD[i][j] = B[i][j] + C[i][j];
        }
    }
}

void reinitialzingD(int **D) {

    for(int i = 0; i < n; i++) {
        memset(D[i], 0, n * 4);
    }

}

void subtraction(int **B, int **C, int **newD) {

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            newD[i][j] = B[i][j] - C[i][j];
        }
    }
}

void copyMat(int **cpyA, int ** B) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cpyA[i][j] = B[i][j];
        }
    }
}

void multiplicationBy2(int **D) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            D[i][j] *= 2;
        }
    }
}

void multiplicationD(int **B, int **C, int **newD) {

    int value = 0, rowsD = 0, colD = 0;

    for(int i = rowsD; i < n; i++) {

        for(int j = 0; j < n; j++) {

            value = value + B[i][j]*C[j][colD];
        }
        newD[rowsD][colD] = value;
        colD++;
        value = 0;
        if(colD < n) {
            i--;
        } else {
            colD = 0;
            rowsD++;
        }

    }

}

int main() {

    scanf("%d", &n);
    int **A = (int **)malloc(sizeof(int*) * n);
    int **B = (int **)malloc(sizeof(int*) * n);
    int **C = (int **)malloc(sizeof(int*) * n);
    int **D = (int **)malloc(sizeof(int*) * n);

    for(int i = 0; i < n; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
        B[i] = (int *)malloc(sizeof(int) * n);
        C[i] = (int *)malloc(sizeof(int) * n);
        D[i] = (int *)malloc(sizeof(int) * n);
    }

    readMat(B);
    printf("\n");
    readMat(C);

    multiplicationD(B, C, D);
    printf("The new matrix after multiplication is\n");
    writeMat(D);
    copyMat(A, D);

    addition(B, C, D);
    printf("The new matrix after addition is\n");
    writeMat(D);
    multiplicationBy2(D);
    subtraction(A, D, A);
    reinitialzingD(D);

    subtraction(B, C, D);
    printf("The new matrix after subtraction is\n");
    writeMat(D);
    reinitialzingD(D);
    printf("\n");

    printf("The matrix A is:\n"); writeMat(A);

    return 0;
}
