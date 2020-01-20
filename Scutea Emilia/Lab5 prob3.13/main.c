#include "header.h"
int main()
{
    int n;
    printf("Please insert the length of the array:\nn=");
    scanf("%d",&n);
    int * array = readArray(n);
    printf("The array is:\n");
    printArray(array,n);
    arrayPerfectSquares(array,n);

}
