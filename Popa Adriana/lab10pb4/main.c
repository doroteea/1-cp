#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int real,imaginary;
} complex;

complex *readCoefficients(int n)
{
    complex *a=(complex*)(malloc(sizeof(complex)*(n+1)));
    int i;
    for(i=0; i<=n; i++)
    {
        printf("\nreal part of coefficient %d:",i);
        scanf("%d",&a[i].real);
        printf("real imaginary of coefficient %d:",i);
        scanf("%d",&a[i].imaginary);
    }
    return a;
}

complex readx()
{
    complex x;
    printf("\nreal part of x = ");
    scanf("%d",&x.real);
    printf("real imaginary of x = ");
    scanf("%d",&x.imaginary);
    return x;
}

complex powerOfx(complex x,int p)
{
    complex a=x;
    int i;
    for(i=1; i<p; i++)
    {
        a.real=(a.real * x.real) + (a.imaginary * x.imaginary);
        a.imaginary=(a.real * x.imaginary) - (a.imaginary * x.real);
    }
    return a;
}

void computeElements(complex *coefficients,complex x,int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        coefficients[i].real=(coefficients[i].real * x.real) + (coefficients[i].imaginary * x.imaginary);
        coefficients[i].imaginary=(coefficients[i].real * x.imaginary) + (coefficients[i].imaginary * x.real);
    }
}

complex polynomialSum(complex *coefficients,complex x,int n)
{
    computeElements(coefficients,x,n);
    int i;
    complex sum;
    sum.real=coefficients[0].real;
    sum.imaginary=coefficients[0].imaginary;
    for(i=1; i<=n; i++)
    {
        sum.real=sum.real+coefficients[i].real;
        sum.imaginary=sum.imaginary+coefficients[i].imaginary;
    }
    return sum;
}

int main()
{
    int n;
    printf("give the degree of the polynomial:\n n=");
    scanf("%d",&n);
    complex *coefficients=readCoefficients(n);
    complex x = readx();
    complex polynomial = polynomialSum(coefficients,x,n);
    printf("your polynomial is equal to %d + %d *i",polynomial.real,polynomial.imaginary);
    return 0;
}
