#include <stdio.h>
#include <stdlib.h>
int ** allocateMatrix(int size)
{
    int ** mat=(int**)malloc(sizeof(int*)*size);
    for(int i=0;i<size;i++)
    {
        *(mat+i)=(int*)malloc(sizeof(int)*size);
    }
    return mat;
}

int ** readMatrix(int size)
{
    int ** mat=allocateMatrix(size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("Please insert the element %d %d:",i,j);
            scanf("%d",(*(mat+i)+j));
        }
    }
    return mat;
}

void printMatrix(int ** mat, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}

int ** equalToZero(int size)
{
    int ** mat=allocateMatrix(size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            *(*(mat+i)+j)=0;
        }
    }
    return mat;
}
int ** multiplicateMatrix(int ** mat1,int ** mat2,int size)
{
    int ** mat=equalToZero(size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                *(*(mat+i)+j) += *(*(mat1+i)+k) * *(*(mat2+k)+j);
            }
        }
    }
    return mat;
}
