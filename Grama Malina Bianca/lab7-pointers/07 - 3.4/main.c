#include <stdio.h>
#include <stdlib.h>

int *readArray(int n) {
    int *array = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("array[%d]=", i + 1);
        scanf("%d", &value);
        *(array + i) = value;
    }

    return array;
}

int *mergeArrays(int *arr1, int *arr2, int n1, int n2, int *n3) {
    int *mergedArray = (int *) malloc(sizeof(int) * (n1 + n2));
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (*(arr1 + i) < *(arr2 + j)) {
            *(mergedArray + k) = *(arr1 + i);
            k++;
            i++;
        } else if (*(arr1 + i) > *(arr2 + j)) {
            *(mergedArray + k) = *(arr2 + j);
            k++;
            j++;
        } else {
            *(mergedArray + k) = *(arr1 + i);
            k++;
            i++;
            j++;
        }
    }
    if (i <= n1) {
        for (int p = i; p < n1; p++) {
            *(mergedArray + k) = *(arr1 + p);
            k++;
        }
    }
    if (j <= n2) {
        for (int p = j; p < n2; p++) {
            *(mergedArray + k) = *(arr2 + p);
            k++;
        }
    }

    *n3 = k;
    return mergedArray;
}

int main() {
    int n1, n2; // lengths of the 2 arrays
    printf("Please input the length of the first array: ");
    scanf("%d", &n1);

    printf("Please input values for the first array (in ascending order): \n");
    int *array1 = readArray(n1);

    printf("The first array is: \n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", *(array1 + i));
    }
    printf("\n");

    printf("Please input the length of the second array: ");
    scanf("%d", &n2);

    printf("Please input values for the second array (in ascending order): \n");
    int *array2 = readArray(n2);

    printf("The second array is: \n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", *(array2 + i));
    }
    printf("\n");

    int n3 = 0; // initialization of the length of the resulting array
    int *mergedArray = mergeArrays(array1, array2, n1, n2, &n3);

    printf("The two arrays merged are: \n");
    for (int i = 0; i < n3; i++) {
        printf("%d ", *(mergedArray + i));
    }

    return 0;
}