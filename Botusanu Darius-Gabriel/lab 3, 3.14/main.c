#include <stdio.h>
#include <stdlib.h>
#include "head.c"
/*I changed the formula as the standards were unrealistic*/
int main()
{
    char gender=getValidGender();
    unsigned int age=readPostivieInteger("age");
    unsigned int height=readPostivieInteger("height");
    printf("\nThis is the ideal weight %2.f kg", idealWeight(gender, age,height));
    return 0;
}
