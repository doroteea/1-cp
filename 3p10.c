#include <stdio.h>
#include <stdlib.h>

int MinimumNoOfBank (int amount, int banknotes[6])
{
    int i = 5, minNumber = 0;
    while (amount > 0 && i >= 0)
    {
        while (banknotes[i] <= amount)
        {
            amount -= banknotes[i];
            minNumber++;
        }
        i--;
    }
    return minNumber;
}

int main ()
{
    int amount, banknotes[6] = {1, 5, 10, 50, 100, 200};
    scanf ("%d", &amount);
    printf ("The minimum number of banknotes needed to pay %d RON is %d", amount, MinimumNoOfBank (amount, banknotes));

    return 0;
}
