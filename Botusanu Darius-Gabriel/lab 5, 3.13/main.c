#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int readPositiveInteger()
{
    int number;
    scanf("%d", &number);
    return number;
}

int checkifPositiveInteger()
{
    int number;
    number=readPositiveInteger();
    while(number<0)
    {
        number=readPositiveInteger();
    }
    return number;
}

int checkPerfectSquare(int number)
{
    if(sqrt(number)-floor(number)==0)
    {
        return 1;
    }
    else
        return 0;

}

int * readIntegerVector(int vectorSize)
{
    int * integerVector=(int*)malloc(sizeof(int)*vectorSize);
    int i;
    printf("\nPlease input the elements of your vector: ");
    for(i=0; i<vectorSize; ++i)
    {
        printf("\nintegerVector[%d]=",i);
        scanf("%d",&integerVector[i]);
    }
    return integerVector;
}

int * perfectSquaresExtractor(int * integerVector, int vectorSize)
{
    int i, j=0;
    int * perfectSquaresVector=(int*)malloc(sizeof(int)*vectorSize);
    for(i=0; i<vectorSize; ++i)
    {
        int check=checkifPositiveInteger(integerVector[i]);
        if(check==1)
        {
            perfectSquaresVector[j]=integerVector[i];
            j++;
        }
    }
    return perfectSquaresVector;
}

int newSize(int * integerVector, int vectorSize)
{
    int i, j=0;
    for(i=0; i<vectorSize; ++i)
    {
        int check=checkifPositiveInteger(integerVector[i]);
        if(check==1)
        {
            j++;
        }
    }
    return j;
}

void vectorPrint(int * vector, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d, ",vector[i]);
    }
}


int main()
{
    int vectorSize;
    printf("Please input the size of your vector:");
    vectorSize=checkifPositiveInteger();
    int * integerVector=readIntegerVector(vectorSize);
    int * perfectSquaresVector=perfectSquaresExtractor(integerVector, vectorSize);
    int newVectorSize=newSize(integerVector, vectorSize);
    printf("\nThis is a vector with the the elements being the perfect squares of your previous vector: ");
    vectorPrint(perfectSquaresVector, newVectorSize);
    return 0;
}
