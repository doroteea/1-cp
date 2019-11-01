/**Given a matrix of n*n elements all0 or1, verify if this matrix is symmetric.
*/
#include <stdio.h>
#include <stdlib.h>
///1 0 1 1
///0 1 0 0  Ex for symmetric matrix
///1 0 1 0
///1 0 0 1
int matrix[100][100];

void read(int n) {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int verifDiagonal(int n) {

    int nr = matrix[0][0];
    for(int i = 1; i < n; i++) {
        if(matrix[i][i] != nr) {
            return 0;
        }
    }

    return 1;
}

int verifMatrix(int n) {

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }

    return 1;

}

int main()
{
    int n;
    scanf("%d", &n); read(n);

    if(verifDiagonal(n) == 0) {
        printf("The matrix is not symmetric.");
    }
    else {

        if(verifMatrix(n) == 0) {
            printf("The matrix is not symmetric");
        }
        else {
            printf("The matrix is symmetric");
        }
    }

    return 0;
}
