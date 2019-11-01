/** Write a function which returns the highest perfect square which is less or equal to its parameter (a positive integer).
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int perfectSquare(int nr) {

    for(int i = nr; i >= 1; i--) {
        if(floor(sqrt(i)) * floor(sqrt(i)) == i) {
            return i;
        }
    }
}

int main()
{
    int n; scanf("%d", &n);
    printf("%d", perfectSquare(n));
    return 0;
}
