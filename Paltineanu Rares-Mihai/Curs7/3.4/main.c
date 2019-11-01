/**Using only pointers and pointer expressions, write a function to merge two vectors.
The given vectors contain real number elements, in ascending order.
The result vector must contain only the distinct elements of the two given vectors, also in ascending order
*/

#include <stdio.h>
#include <stdlib.h>
#include "merge.h"
#include "read.h"
#include "sort.h"
#include "write.h"

int main()
{
    int size1, size2, size3 = 0;
    printf("Read the size for two arrays: ");
    scanf("%d %d", &size1, &size2);

    int *vect1 = (int *)malloc(sizeof(int) * size1);
    int *vect2 = (int *)malloc(sizeof(int) * size2);
    int *vect3 = (int *)malloc(sizeof(int) * (size1 + size2));

    printf("Read the first array: ");
    read(vect1, size1);

    printf("Read the second array: ");
    read(vect2, size2);


    sortVect(vect1, size1);
    sortVect(vect2, size2);

    printf("The first array in ascending order is: "); write(vect1, size1);
    printf("The second array in ascending order is: "); write(vect2, size2);

    mergeVect(vect1, size1, vect2, size2, vect3, &size3);

    vect3 = (int*)realloc(vect3, size3 * sizeof(int));

    printf("The vector containing the distinc elements from the two arrays in ascending order is:\n"); write(vect3, size3);
    return 0;
}
