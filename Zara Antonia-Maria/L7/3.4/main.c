/// 3.4. Using only pointers and pointer expressions, write a function to merge two vectors.
///      The given vectors contain real number elements, in ascending order.
///      The result vector must contain only the distinct elements of the two given vectors, also in ascending order.


#include <stdio.h>
#include <stdlib.h>

void interclasare(float *v1, float *v2, int l1, int l2)
{
    int i,j,k;
    float *vf=(float*)malloc(sizeof(float)*(l1+l2));
    i=0;j=0;k=0;

    while(i<=l1 && j<=l2)
    {
        if(v1[i]<v2[j])
        {
            vf[k++]=v1[i++];
        }
        if(v1[i]>v2[j])
        {
            vf[k++]=v2[j++];
        }
        if(v1[i]==v2[j])
        {
            vf[k++]=v2[j++];
            i++;
        }
        printf("%f %f %d\n",v1[i],v2[j],k);
    }
    while(i<=l1)vf[k++]=v1[i++];
    while(j<=l2)vf[k++]=v2[j++];

    printf("%d\n",k);

    for(i=0;i<k;i++)
        printf("%f ",vf[i]);
}

int main()
{
    int length1,length2,i;

    printf("Input length of the first vector: ");
    scanf("%d",&length1);
    float *vector1=(float*)malloc(sizeof(float)*length1);
    printf("Input the elements of the first vector: ");
    for(i=0;i<length1;i++)
        scanf("%f",&vector1[i]);

    printf("\nInput length of the second vector: ");
    scanf("%d",&length2);
    float *vector2=(float*)malloc(sizeof(float)*length2);
    printf("Input the elements of the first vector: ");
    for(i=0;i<length2;i++)
        scanf("%f",&vector2[i]);

    interclasare(vector1,vector2,length1,length2);

    return 0;
}
