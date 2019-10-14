/*Write a program to calculate the value z= xy, for variables xandyof the type double.
Hint: look for function pow
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long x, y,z;
    scanf("%ld", &x);
    scanf("%ld", &y);
    z = pow(x,y);
    printf("z = %ld", z);

    return 0;
}
