/**Write the complementary function,
which converts a base 10 Arabian number to a number written with Roman numerals.
*/
#include <stdio.h>
#include <stdlib.h>
char roman1[3][3] = {"M", "MM", "MMM"};
char roman2[9][5] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char roman3[9][5] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char roman4[9][5] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
int conversion(int nr, char *roman) {

    int arab, size = 0;

    arab = nr / 1000;
    if(arab != 0)
        for(int i = 0; i < strlen(roman1[arab - 1]); i++)
            roman[size++] = roman1[arab - 1][i];

    arab = nr / 100 % 10;
    if(arab != 0)
        for(int i = 0; i < strlen(roman2[arab - 1]); i++)
            roman[size++] = roman2[arab - 1][i];

    arab = nr / 10 % 10;
    if(arab != 0)
        for(int i = 0; i < strlen(roman3[arab - 1]); i++)
            roman[size++] = roman3[arab - 1][i];

    arab = nr % 10;
    if(arab != 0)
        for(int i = 0; i < strlen(roman4[arab - 1]); i++)
            roman[size++] = roman4[arab - 1][i];

    printf("%s", roman);
}

int main() {
    int nr;
    scanf("%d", &nr);
    char roman[30];
    memset(roman, '\0', sizeof(roman));
    conversion(nr, roman);
    return 0;
}
