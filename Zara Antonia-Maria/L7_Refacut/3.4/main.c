/** write a function to merge two vectors. The given vectors contain real number elements, in ascending order.
    The result vector must contain only the distinct elements of the two given vectors, also in ascending order.*/

#include <stdio.h>
#include <stdlib.h>

double *read(int length)
{
    double *vector = (double*)malloc(sizeof(double*)*length);
    int i;
    printf("Input the elements of the vector: ");
    for(i=0; i<length; i++)
    {
        scanf("%lf",&vector[i]);
    }
    return vector;
}

double *merge(double *vector1, double *vector2, int length1, int length2, int *finalVectorLength)
{
    int currentPosition=0,i=0,j=0;
    double *finalVector = (double*)malloc(sizeof(double*)*(length1+length2));

    while(i<length1 && j<length2)
    {

                if(vector1[i]<vector2[j])
                {
                    finalVector[currentPosition++] = vector1[i++];
                }
                if(vector1[i]>vector2[j])
                {
                    finalVector[currentPosition++] = vector2[j++];
                }
                if(vector1[i]==vector2[j])
                {
                    finalVector[currentPosition++] = vector1[i++];
                    j++;
                }

    }
    while(i<length1)
    {
        finalVector[currentPosition++] = vector1[i++];
    }
    while(j<length2)
    {
        finalVector[currentPosition++] = vector2[j++];
    }

    finalVectorLength[0] = currentPosition;

    return finalVector;
}

void print(double *finalVector, int *finalVectorLength)
{
    int i;
    for(i=0; i<finalVectorLength[0]; i++)
    {
        printf("%lf ",finalVector[i]);
    }
}

int main()
{
    int length1,length2;

    printf("Input the length of the first vector: ");
    scanf("%d",&length1);

    printf("Input the length of the second vector: ");
    scanf("%d",&length2);

    double *vector1 = (double*)malloc(sizeof(double*)*length1);
    double *vector2 = (double*)malloc(sizeof(double*)*length2);

    vector1 = read(length1);
    vector2 = read(length2);

    double *finalVector = (double*)malloc(sizeof(double*)*(length1+length2));

    int *finalVectorLength = (int*)malloc(sizeof(int*)*1);

    finalVector = merge(vector1,vector2,length1,length2,finalVectorLength);

    print(finalVector,finalVectorLength);

    return 0;
}
