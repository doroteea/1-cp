#include <stdio.h>
#include <stdlib.h>

void ConvertToRoman (int nr, char **table)
{
    int power = 0, div = 1;
    while (nr / div > 9)
    {
        power++;
        div *= 10;
    }
    while (power >= 0)
    {
        printf ("%s", table[power][nr / div]);
        nr %= div;
        power--; div /= 10;
    }
}

int main ()
{
    char *table[4][10] =
    {
        {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
        },
        {
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
        },
        {
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
        },
        {
            "", "M", "MM", "MMM"
        }
    };
    int nr;
    scanf ("%d", &nr);
    ConvertToRoman (nr, table);
    return 0;
}
