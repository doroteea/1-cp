#include <stdio.h>
#include <stdlib.h>


void merge_vectors(float *v1,float *v2,int n1,int n2)
{
    int i=0,j=0,k=0;
    int n3=n1+n2;
    float *v3=(float*)malloc(sizeof(float)*n3);
    while(i<n1 && j<n2)
    {
        if(v1[i]<v2[j])
        {
            v3[k++]=v1[i++];
        }
        else
        {
            if(v1[i]==v2[j])
            {
                v3[k++]=v1[i];
                i++;
                j++;
            }
            else
            {
                v3[k++]=v2[j++];
            }
        }


    }
    while(i<n1)
    {
        v3[k++]=v1[i++];
    }
    while(j<n2)
    {
        v3[k++]=v2[j++];
    }

    for(i=0; i<k; i++)
    {
        printf("%f   ",v3[i]);
    }



}
int main()
{
    int n1,n2;
    int i;
    printf("Introduce the number of elements for the first vector:\n");
    scanf("%d",&n1);
    float *v1=(float*)malloc(sizeof(float)*n1);

    for(i=0; i<n1; i++)
    {
        printf("v1[%d]=",i);
        scanf("%f",&v1[i]);
    }
    printf("Introduce the number of elements for the second vector:\n");
    scanf("%d",&n2);

    float *v2=(float*)malloc(sizeof(float)*n2);

    for(i=0; i<n2; i++)
    {
        printf("v2[%d]=",i);
        scanf("%f",&v2[i]);
    }

    merge_vectors(v1,v2,n1,n2);


    return 0;
}
