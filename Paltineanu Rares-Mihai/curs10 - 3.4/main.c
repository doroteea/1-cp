/**Write a program to compute the value of a polynomial of degree n with complex coefficients for a given complex value.
 Use functions o implement computations
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {

    char *coeff;
} polynomial;

void initialize(polynomial *v, int n) {

    for(int i = 0; i <= n; i++) {

        v[i].coeff = (char *)malloc(sizeof(char) * 10);

    }
}

void read(polynomial *v, int n) {

    printf("Enter the coefficients of the polynomial:\n");

    for(int i = 0; i <= n; i++) {

        gets(v[i].coeff);

        while(strchr(v[i].coeff, 'i') == NULL) {

            printf("Please read a complex coefficient.\n");
            gets(v[i].coeff);
        }

    }
}

long combination(int n, int k) {

    long nr = 1;

    if(k == 0) {
        return 1;
    }

    if(k == n) {
        return 1;
    }

    if(k == 1) {
        return n;
    }

    for(int i = 0; i < k; i++) {

        nr = nr * (n - i) / (k - i);

    }

    return nr;

}

void takeTheValues(long *real, long *imaginary, char *vect) {

    ///I know that i could have in the struct int real, imaginary; and then read the coefficients, but i wanted to make the things more complicated
    ///and i made it only for integer numbers

    int i = 0;
    if(strlen(vect) == 1) {

        *imaginary = 1;

    } else {

        if(vect[0] != '-' && strchr(vect, '+') == NULL && strchr(vect, '-') == NULL) {
            ///ex: 6i

            i = 0;

            while(vect[i] >= '0' && vect[i] <= '9') {

                *imaginary *= 10;
                *imaginary += (vect[i] - '0');
                i++;

            }
        } else {
            if(vect[0] == '-' && (strchr(vect + 1, '+') == NULL &&  strchr(vect + 1, '-') == NULL)) {
                ///ex: -4i
                i = 1;

                if(vect[1] == 'i') {

                    /// -i
                    *imaginary = -1;

                } else {

                    while(vect[i] >= '0' && vect[i] <= '9') {

                        *imaginary *= 10;
                        *imaginary += (vect[i] - '0');
                        i++;

                    }

                    *imaginary *= (-1);

                }


            } else {

                if(vect[0] == '-' && (strchr(vect + 1, '+') != NULL ||  strchr(vect + 1, '-') != NULL)) {
                    ///ex: -2 + 3i; -4 - 5i
                    i = 1;

                    while(vect[i] >= '0' && vect[i] <= '9') {

                        *real *= 10;
                        *real += (vect[i] - '0');
                        i++;

                    }
                    *real *= (-1);

                    while((vect[i] < '0' || vect[i] > '9') && i < strlen(vect)) {

                        i++;

                    }
                    if(i == strlen(vect)) {

                        if(strchr(vect + 1, '+') != NULL) {

                            *imaginary = 1;

                        } else {

                            *imaginary = (-1);

                        }

                    } else {


                        while(vect[i] >= '0' && vect[i] <= '9') {

                            *imaginary *= 10;
                            *imaginary += (vect[i] - '0');
                            i++;

                        }

                        if(strchr(vect + 1, '-') != NULL) {

                            *imaginary *= (-1);

                        }
                    }
                } else {

                    if(vect[0] != '-' && ((strchr(vect, '-') != NULL) || strchr(vect, '+') != NULL)) {
                        ///ex:4 + 2i; 4 - 2i
                        i = 0;

                        while(vect[i] >= '0' && vect[i] <= '9') {

                            *real *= 10;
                            *real += (vect[i] - '0');
                            i++;

                        }

                        while((vect[i] < '0' || vect[i] > '9') && i < strlen(vect)) {

                            i++;

                        }

                        if(i == strlen(vect)) {
                            ///ex: 4 - i; 4 + i
                            if(strchr(vect, '-') != NULL) {

                                *imaginary = -1;

                            } else {

                                *imaginary = 1;

                            }

                        } else {


                            while((vect[i] < '0' || vect[i] > '9') && i < strlen(vect)) {

                                i++;

                            }

                            while(vect[i] >= '0' && vect[i] <= '9') {

                                *imaginary *= 10;
                                *imaginary += (vect[i] - '0');
                                i++;

                            }

                            if(strchr(vect, '-') != NULL) {

                                *imaginary *= (-1);

                            }
                        }
                    }
                }
            }
        }
    }
}

void computeValue(polynomial *v, int n, char *valueForPol) {

    long realPartOfValueForPol = 0;
    long imaginaryPartOfValueForPol = 0;
    takeTheValues(&realPartOfValueForPol, &imaginaryPartOfValueForPol, valueForPol);

    long valueOfRealCoeff = 0;
    long valueOfImaginaryCoeff = 0;

    long newReal = 0;
    long newImaginary = 0;

    long combin;

    takeTheValues(&newReal, &newImaginary, v[0].coeff);

    for(int i = 1; i <= n; i++) {

        takeTheValues(&valueOfRealCoeff, &valueOfImaginaryCoeff, v[i].coeff);
        printf("%ld %ld\n\n", valueOfRealCoeff, valueOfImaginaryCoeff);
        for(int j = 0; j <= i; j++) {

            combin = combination(i, j);
            ///a^(i-j)*b(^j)

            switch(j % 4) {
            /**
            i - 1
            -1 - 2
            -i - 3
            1 - 4
            */
            case 0:

                newReal += valueOfRealCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));
                newImaginary += valueOfImaginaryCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));

                break;

            case 1:

                newReal -= valueOfImaginaryCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));
                newImaginary += valueOfRealCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));

                break;

            case 2:

                newReal -= valueOfRealCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));
                newImaginary -= valueOfImaginaryCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));

                break;

            case 3:

                newReal += valueOfImaginaryCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));
                newImaginary -= valueOfRealCoeff * combin * (pow(realPartOfValueForPol, i - j)) * (pow(imaginaryPartOfValueForPol, j));

                break;

            }

        }

        valueOfRealCoeff = 0;
        valueOfImaginaryCoeff = 0;
    }

    if(newImaginary > 0) {

        printf("%ld + %ldi", newReal, newImaginary);

    }
    else {

        newImaginary *= (-1);
        printf("%ld - %ldi", newReal, newImaginary);

    }
}

int main() {

    int n;

    char *value = (char *)malloc(sizeof(char) * 10);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the value of the polynomial: ");
    gets(value);

    polynomial *vect = (polynomial *)malloc(sizeof(polynomial) * n);
    initialize(vect, n);

    read(vect, n);
    computeValue(vect, n, value);
    //printf("%ld", combination(6,2));
    return 0;
}
