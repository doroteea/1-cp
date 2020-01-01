#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int highestPerfectSquare(int nr)
{
    while((sqrt(nr) * sqrt(nr)) != nr)
    {
        nr--;
    }
    return nr;
}
int main()
{
    int nr;
    printf("Please insert the number:\nnr=");
    scanf("%d",&nr);
    printf("The highest perfect square which is less or equal to %d is %d.",nr,highestPerfectSquare(nr));
}
