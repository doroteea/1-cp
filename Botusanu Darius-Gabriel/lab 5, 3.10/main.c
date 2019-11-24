#include <stdio.h>
#include <stdlib.h>
#include "header.c"
/*Greedy method*/

int main()
{
    long amount=readAmount();
    printf("\nThis is the minimum amount of banknotes necessary for completing the amount: %d", minimumNumber(amount));
    return 0;
}





















