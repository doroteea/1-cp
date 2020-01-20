#include <stdio.h>
#include <stdlib.h>
int r;
int c;


void readMatrix(int **arr[],int r,int c)
{

    printf("Please insert the number of rows:\nr=");
    scanf("%d",&r);
    printf("Please insert the number of columns:\nc=");
    scanf("%d",c);

    int **arr=(int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
    {
        arr[i]=(int*)malloc(c*sizeof(int));
    }

    for(int i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("a[%d]][%d]=",i,j);
            scanf("%d",arr[i][j]);
        }
    }
}

void displayMatrix(int **arr[])
{
    for(int i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int **arr1=readMatrix(**arr1,r,c);

    displayMatrix(**arr1);

    return 0;
}
