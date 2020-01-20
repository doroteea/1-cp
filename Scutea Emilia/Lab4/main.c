#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int n=10;
    int s[20];//static
    int *s2=(int*)malloc(sizeof(int)*n);


    int i=10;
    int *j=(int*)malloc(sizeof(int));
    j[0]=8;
    *j=8;
    printf("%d",*j);*/


    int rows=4,cols=4;

    int **mat=(int**)malloc(sizeof(int*)*rows);
    for(int i=0;i<rows;i++){
        mat[i]=(int*)malloc(sizeof(int)*cols);
    }
    for(int r=0;r<rows;r++){
        for(int c=0;c<cols;c++){
            printf("mat[%d][%d]=",r,c);
            scanf("%d",&mat[r][c]);
        }
    }

    return 0;
}
