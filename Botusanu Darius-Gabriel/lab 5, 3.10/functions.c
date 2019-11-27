#include <stdio.h>
#include <stdlib.h>

void howMany(long *amount, int *banknotesNumber, int banknote)
{
    while(*amount>=banknote)
    {
        *banknotesNumber+=1;
        *amount-=banknote;
    }
}

int minimumNumber(long amount)
{
    int i, banknotesNumber=0;
    int ronBanknotes[7]={500,200,100,50,10,5,1};
    for(i=0;i<7;i++)
    {
        howMany(&amount, &banknotesNumber, ronBanknotes[i]);
    }
    return banknotesNumber;
}

long readAmount()
{
    long amount;
    printf("Please enter the amount of money: ");
    scanf("%ld",&amount);
    return amount;
}
