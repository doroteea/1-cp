#include <stdio.h>

void countCurrency(int amount)
{
    int notes[7] = { 500, 200, 100,
                     50, 10, 5, 1 };

    int noteCounter[9] = { 0 };

    for (int i = 0; i < 7; i++)
    {
        if (amount >= notes[i])
        {
            noteCounter[i] = amount / notes[i];
            amount = amount - noteCounter[i] * notes[i];
        }
    }

    printf("Currency Count:\n");
    for (int i = 0; i < 9; i++)
    {
        if (noteCounter[i] != 0)
        {
            printf("%d: %d \n", notes[i],noteCounter[i]);
        }
    }
}

int main()
{
    int amount;
    scanf("%d", &amount);
    countCurrency(amount);
    return 0;
}