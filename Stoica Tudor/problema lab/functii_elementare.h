//
// Created by stoic on 23 oct. 2019.
//

#ifndef PROBLEMA_LAB_FUNCTII_ELEMENTARE_H
#define PROBLEMA_LAB_FUNCTII_ELEMENTARE_H

#endif //PROBLEMA_LAB_FUNCTII_ELEMENTARE_H

#include <stdio.h>

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void cin_int(int *a) {
    scanf("%d", a);
}

int readInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int readNextIntMat(int mat[][], int size) {

    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            scanf("%d", &mat[i][j]);
        }
    }
}

void cin_char(char *a) {
    scanf("%c", a);
}