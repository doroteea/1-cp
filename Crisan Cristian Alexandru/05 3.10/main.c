#include <stdio.h>
#include <stdlib.h>
/*3.10. Read an integer representing an amount of money
expressed in RON from the standard input.
Write a function to determine the minimum number of banknotes
needed to pay that amount. */
int A[7]={500,200,100,50,10,5,1};
void HowManyOf(int *AmountOfMoney,int *NrOfBanknotes,int Banknote)
{
    while(*AmountOfMoney>=Banknote)
    {
        *NrOfBanknotes=*NrOfBanknotes+1;
        *AmountOfMoney=*AmountOfMoney-Banknote;
    }

}
int MinimumNrOfBanknotes(int AmountOfMoney)
{
    int NrOfBanknotes=0;
   for(int i=0;i<7;i++)
   {
       HowManyOf(&AmountOfMoney,&NrOfBanknotes,A[i]);
   }

    return NrOfBanknotes;
}

int main()
{
    int AmountOfMoney;
    scanf("%d",&AmountOfMoney);
    printf("One needs a minimum of %d banknotes to pay %d RON.",MinimumNrOfBanknotes(AmountOfMoney),AmountOfMoney);
    return 0;
}
