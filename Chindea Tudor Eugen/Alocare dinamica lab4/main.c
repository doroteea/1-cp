#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=20;
    int* shir=(int*)malloc(sizeof(int)*n);// imi aloca 80 bytes,
    *(shir+8) // shir[2];
    int* i=(int*)malloc(sizeof(int));// alocare dinamica a unui numar
    *i=2;
    i[0]=2;

    return 0;
}
