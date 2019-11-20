#include <stdio.h>
#include <stdlib.h>

int x, f;

int main()
{
    scanf ("%d", &x);
    if (x < -2){
        f = x * x - 7 * x + 4;
    }
    else
    {
        if (x == -2){
            f = 0;
        }
        else{
            f = x * x + 5 * x - 2;
        }
    }
    printf ("%d", f);
    return 0;
}
