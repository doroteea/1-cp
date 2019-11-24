#include <stdio.h>
#include <stdlib.h>

//struct Car
//{
//    int fabYear;
//    char *name;
//    char *owner;
//}Car;
//struct Car vw;

typedef struct
{
    int fabYear;
    char *name;
    char *owner;
}Car, Vehicle;
Car vw;
Vehicle x;

Car assemble (Car a)
{
    a.fabYear=5;
}

Car Assemble (Car *a)
{
    a->fabYear=5;
//    (*a).
}

int main()
{
    Car *cars=(Car*)malloc(sizeof(Car)*10);

    return 0;
}
