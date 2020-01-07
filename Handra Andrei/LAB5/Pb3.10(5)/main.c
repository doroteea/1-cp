#include <stdio.h>
#include <stdlib.h>

int MinNrOfBnknotes(int);

int main()
{
    int nrofbanknotes,amount;
    printf("Please type in the amount: ");
    scanf("%d",&amount);
    nrofbanknotes=MinNrOfBnknotes(amount);
    printf("The minimum number of banknotes is: %d ",nrofbanknotes);


    return 0;
}

int MinNrOfBnknotes(int amount)
{
    int i,nrofbnknotes;
    nrofbnknotes=0;
    int *bnknote=(int *)malloc(sizeof(int)*7);
    bnknote=(int[7]){1,5,10,50,100,200,500};
    i=6;
    while( amount>0)
    {
        if(amount>=bnknote[i])
        {
            amount=amount-bnknote[i];
            nrofbnknotes++;
        }
        else
        {
            i--;
        }
    }
    return nrofbnknotes;
}
