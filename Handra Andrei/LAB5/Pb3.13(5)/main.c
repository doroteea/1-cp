#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void PerfSquare(int *,int,int *,int *);

int main()
{
    int nr,i,k;
    printf("Please type in the number of elements in the array: ");
    scanf("%d",&nr);
    int *Array=(int *)malloc(sizeof(int)*nr);
    for(i=0;i<nr;i++)
    {
        scanf("%d",&Array[i]);
    }
    int *PerfArray=(int *)malloc(sizeof(int)*nr);
    k=0;
    PerfSquare(Array,nr,PerfArray,&k);
    for(i=0;i<k;i++)
    {
        printf("%d ",PerfArray[i]);
    }

    return 0;
}

void PerfSquare(int *array,int n,int *perfarray,int *k)
{
    int i,x,nr;
    nr=0;
    for(i=0;i<n;i++)
    {
        x=sqrt(array[i]);
        if(x*x==array[i])
        {
            perfarray[nr]=array[i];
            nr++;
        }
    }
    *k=nr;
}
