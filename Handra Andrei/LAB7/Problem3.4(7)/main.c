#include <stdio.h>
#include <stdlib.h>

void mergeVectors(int n,int *k,float *vector1,float *vector2,float *mergedVector)
{
    int i,j;
    i=j=0;
    while(i<n && j<n)
    {
        if(vector1[i]<vector2[j])
        {
            mergedVector[(*k)++]=vector1[i];
            i++;
        }
        else
        {
            if(vector1[i]>vector2[j])
            {
            mergedVector[(*k)++]=vector2[j];
            j++;
            }
            else
            {
            i++;
            j++;
            }
        }
    }
    while(i<n)
    {
        mergedVector[(*k)++]=vector1[i];
        i++;
    }
    while(j<n)
    {
        mergedVector[(*k)++]=vector2[j];
        j++;
    }
}
int main()
{
    int n,i,k=0;
    printf("Enter the size of the vector: ");
    scanf("%d",&n);
    float *vector1=(float*)malloc(sizeof(float)*n);
    float *vector2=(float*)malloc(sizeof(float)*n);
    float *mergedVector=(float*)malloc(sizeof(float)*2*n);
    for(i=0;i<n;i++)
    {
        scanf("%f",&vector1[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%f",&vector2[i]);
    }
    mergeVectors(n,&k,vector1,vector2,mergedVector);
    for(i=0;i<k;i++)
    {
        printf("%.2f ",mergedVector[i]);
    }
    return 0;
}
