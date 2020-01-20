#include "cars.h"

int main()
{
    int n=0;
    cars *c=readCars(&n);
   // printCars(n,c);
    cars *sortedCars=sortCars(n,c);
    printCars(n,sortedCars);
    return 0;
}
