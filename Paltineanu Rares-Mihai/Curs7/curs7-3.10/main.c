/**Write a function to calculate the transposed of a matrix,
using pointers and pointer expressions to access to the elements of the matrix.
The resulted matrices shall be displayed as a bi-dimensional table.
*/
#include <stdio.h>
#include <stdlib.h>

void readMat(int ***mat, int rows, int col) {

    printf("Read the matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void transposed(int **mat, int ***tr, int rows, int col) {

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            tr[j][i] = mat[i][j];
        }
    }
}

void write(int **tr, int rows, int col) {

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", tr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, col;
    printf("Read the rows and the columns: ");
    scanf("%d %d", &rows, &col);

    int **mat = (int **)malloc(sizeof(int *) * rows);


    for(int i = 0; i < rows; i++) {
        mat[i] = (int *)malloc(sizeof(int) * col);
    }

    readMat(mat, rows, col);

    int **tr = (int **)malloc(sizeof(int *) * col);

    for(int i = 0; i < col; i++) {
        tr[i] = (int *)malloc(sizeof(int) * rows);
    }

    transposed(mat, tr, rows, col);
    printf("\n");
    write(mat, rows, col);
    printf("\n");
    write(tr, col, rows);
    return 0;
}
