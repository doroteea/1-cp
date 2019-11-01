#include <stdio.h>
#include <stdlib.h>

void write(int *s1, int size) {

    for(int i = 0; i < size; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}
