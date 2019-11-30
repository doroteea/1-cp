/**
Read the real part and imaginary part of n complex numbers.
Then create a file containing the complex numbers your program read including the real part, the imaginary part,
the modulus and argument for each number
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415

typedef struct {

    int real;
    int imaginary;

}numbers;

void read(numbers *v, int n, FILE *in, FILE *out) {

    for(int i = 0; i < n; i++) {

        fscanf(in, "%d %d", &v[i].real, &v[i].imaginary);

    }

}

void write(numbers *v, int n, FILE *out) {

    float mod = 0, arg = 0;
    for(int i = 0; i < n; i++) {
        arg = atan((double)v[i].imaginary/v[i].real) * 180 / PI;
        mod = sqrt(v[i].real * v[i].real + v[i].imaginary * v[i].imaginary);
        if(v[i].imaginary > 0) {

            fprintf(out, "%d + %di", v[i].real, v[i].imaginary);

        }
        else {

            fprintf(out, "%d %di", v[i].real, v[i].imaginary);

        }
        fprintf(out, ", modulus = %f, argument = %f \n", mod, arg);
    }

}

int main()
{
    FILE *in;
    in = fopen("number.in", "r");

    FILE *out;
    out = fopen("number.out", "a");
    int n;
    fscanf(in, "%d", &n);
    numbers *vect = (numbers *)malloc(sizeof(numbers) * n);

    read(vect, n, in, out);
    //printf("%d", vect[2].real);
    write(vect, n, out);
    printf("%lf", tan(63.4 * 180 / PI));
    fclose(in);
    fclose(out);
    return 0;
}
