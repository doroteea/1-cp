#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPerfectSquare(int x)
{
    if(sqrt(x) * sqrt(x) == x)
        return 1;
    return 0;
}

int * readArray(int n)
{
    int * array=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        printf("Please insert the element %d:",i);
        scanf("%d",(array+i));
    }
    return array;
}

void printArray(int * array,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(array+i));
    }
    printf("\n");
}

void arrayPerfectSquares(int * array,int n)
{
    int * newArray=(int*)malloc(sizeof(int)*n);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(isPerfectSquare(*(array+i))==1)
        {
            *(newArray+j)=*(array+i);
            j++;
        }
    }
    printf("The array containing only the perfect squares is:\n");
    printArray(newArray,j);
}
