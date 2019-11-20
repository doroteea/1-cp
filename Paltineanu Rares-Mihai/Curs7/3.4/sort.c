#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void sortVect(int *s1, int size) {

    bool ready = false;
    int aux;

    while(!ready) {

        ready = true;

        for(int i = 0; i < size - 1; i++) {
            if(s1[i] > s1[i + 1]) {
                aux = s1[i];
                s1[i] = s1[i + 1];
                s1[i + 1] = aux;
                ready = false;
            }
        }

    }
}
