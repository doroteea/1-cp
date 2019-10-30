#include <stdio.h>
#include <stdlib.h>

void read(int *v, int size) {

    for(int i = 0; i < size; i++) {
        scanf("%d", &v[i]);
    }
}
