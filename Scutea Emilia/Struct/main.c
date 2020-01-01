#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int fabYear;
    char *name;
    char *owner;
}Car,Vehicle;

Car assemble1(Car a)
{
    a.fabYear=5;
}

Car assemble2(Car *a)
{
    (*a).fabYear=6;
}

int main()
{
    Car polo;
    Vehicle x;
    Car *cars=(Car*)malloc(sizeof(Car)*10);

}
