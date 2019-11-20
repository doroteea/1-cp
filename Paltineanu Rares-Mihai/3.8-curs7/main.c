/**Write  a  function  to  compute  the  product  of  two  polynomials,  using  only  pointers  and  pointerexpressions.
*/
#include <stdio.h>
#include <stdlib.h>

///I tried to allocate dynamically the array inside the "read" function, but the program did not work

void read(int *pol, int *size) {

    printf("Read the size: ");
    vscanf("%d", &size);
    memset(pol, 0, sizeof(int) * ((*size) + 1));

    printf("Read the coefficients: ");
    for(int i = 0; i <= *size; i++) {
        scanf("%d", &pol[i]);
    }
}

void product(int *pol1, int *pol2, int *pol3, int size1, int size2) {

    for(int i = 0; i <= size1; i++) {
        for(int j = 0; j <= size2; j++) {
            pol3[i + j] = pol3[i + j] + pol1[i] * pol2[j];
        }
    }
}

void write(int *pol, int size) {

    for(int i = 0; i <= size; i++) {
        printf("%d ", pol[i]);
    }
}

int main() {

    int size1, size2;

    int *pol1 = (int *)malloc(sizeof(int) * 100);
    int *pol2 = (int *)malloc(sizeof(int) * 100);

    read(pol1, &size1);
    read(pol2, &size2);

    int *newpol = (int *)malloc(sizeof(int) * 200);
    memset(newpol, 0, sizeof(int) * 200);

    printf("\n\n");
    product(pol1, pol2, newpol, size1, size2);

    printf("The new polynomial is: ");
    write(newpol, size1 + size2);
    return 0;

}
