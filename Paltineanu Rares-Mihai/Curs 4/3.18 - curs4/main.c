/**Given a natural number n,
a)Find the number obtained by eliminating those digits that appear more than once in that number.
b)Find the number obtained by switching the first digit with the last one, the second with the next to last one, and so on.
c)Find the biggest number that could be obtained by a combination of its digits.
*/
#include <stdio.h>
#include <stdlib.h>

int cif[10], vectCif[11];

void switchVect(int size) {

    int aux;
    for(int i = 0; i < size / 2; i++) {
        aux = vectCif[i];
        vectCif[i] = vectCif[size - i-1];
        vectCif[size - i-1] = aux;
    }

}

int OneDigit(int size, int n) {

    for(int i = size - 1; i >= 0; i--) {
        if(cif[vectCif[i]] == 1) {
            n = n * 10 + vectCif[i];
        }
    }

    return n;
}

int buildN(int size, int n) {

    for(int i = size - 1; i >= 0; i--) {
        n = n * 10 + vectCif[i];
    }

    return n;
}

int biggestNumber(int n) {

    for(int i = 9; i >= 0; i--) {

        if(cif[i] != 0) {

            for(int j = 0; j < cif[i]; j++) {
                n = n *10 + i;
            }
        }
    }

    return n;

}

int main() {

    int n, newN, sizeVectCif = 0;
    scanf("%d", &n);
    newN = n;

    while(newN != 0) {

        vectCif[sizeVectCif++] = newN % 10;
        cif[newN % 10]++;
        newN /= 10;

    }

    /// a !!!!!!!!!!!!
    newN = 0;
    printf("The number obtained by eliminating those digits that appear more than once in the number is: %d\n\n", OneDigit(sizeVectCif, newN));

    /// b !!!!!!!!!!!!
    newN = 0;
    switchVect(sizeVectCif);
    printf("The number obtained at B is: %d\n\n", buildN(sizeVectCif, newN));

    /// c !!!!!!!!!!!!!
    newN = 0;
    printf("The biggest number that could be obtained by a combination of its digits is: %d\n", biggestNumber(newN));
    return 0;
}
