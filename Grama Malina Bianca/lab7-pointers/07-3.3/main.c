#include <stdio.h>
#include <stdlib.h>

void swap(float *element1Ptr, float *element2Ptr) {
    float aux = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = aux;
}

void bubbleSort(float *const array, const int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap((array + j), (array + j+1));
            }
        }
    }
}

int main(){
    int n;
    printf("Please insert length of array: ");
    scanf("%d", &n);
    float *array = (float *) malloc(sizeof(float *) * n);
    for (int i = 0; i < n; i++) {
        printf("array[%d]= ", i);
        scanf("%f", (array + i));
    }

    printf( "Data items in original order\n" );
    for (int i = 0; i < n; i++) {
        printf("%.2f ", *(array + i));
    }

    bubbleSort( array, n );
    printf( "\nData items in ascending order\n" );
    for (int i = 0; i < n; i++) {
        printf("%.2f ", *(array + i));
    }

    return 0;
}