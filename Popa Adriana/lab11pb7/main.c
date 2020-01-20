#include "complex.h"

int main()
{
    FILE *f;
    f=fopen("complex.out","w");
    Complex *c=readComplex();
    printComplex(c,f);
    int *mod=calculateModulus(c);
    printModulus(mod,f);
    int *arg=calculateArgument(c);
    printArgument(arg);
    fclose(f);
    return 0;
}
