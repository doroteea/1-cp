#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10;
    int b=20;
    int *p,*q;
    p=&a;
    q=&b;
    printf("The sum of a and b is equal to %d",*p+*q);


    return 0;
}
