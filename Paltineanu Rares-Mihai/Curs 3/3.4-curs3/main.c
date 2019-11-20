/*Write a program thatreadsa positive integer number in the range [1600, 4900].
Knowing that that number represents a year, check whether that year is bissextile or not
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y;
    scanf("%d", &y);

    if(!(y%100 || y%400) || (!(y%4) && y%100))
        printf("%d is Bissextile year\n", y);
    else
        printf("%d is not Bissextile year\n", y);

    return 0;
}
