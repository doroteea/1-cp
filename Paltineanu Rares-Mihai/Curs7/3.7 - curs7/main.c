/**Write a function to compute the value of the derivative of a polynomial, P(x), of degree n, in a given point x=x0.
 The degree, and the coefficients of the polynomial, and the point, x0, will be passed as parameters. You must use pointers
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read(int *vect, int size, int *x) {

    printf("Read the value x: ");
    vscanf("%d", &x);

    printf("Read the coefficients of the polynomial: ");
    for(int i = 0; i <= size; i++) {
        scanf("%d", &vect[i]);
    }

}

void valueDev(int *pol, int degree, int x, double *valueX) {

    for(int i = 0; i <= degree - 1; i++) {
        *valueX = *valueX + (double)(((i + 1) * pol[i + 1]) * pow(x, i));
    }
}

int main()
{
    int degree, x;
    double val = 0;

    printf("Read the degree of the polynomial: ");
    scanf("%d", &degree);

    int *pol = (int *)malloc(sizeof(int) * (degree + 1));

    read(pol, degree, &x); printf("%d\n\n\n", x);
    valueDev(pol, degree, x, &val);

    printf("The value is: %lf", val);
    return 0;
}
