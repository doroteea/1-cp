#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, og, x;
    scanf ("%d", &n);
    x = n;
    og = 0;
    while (x > 0)
    {
        og = og * 10 + x % 10;
        x /= 10;
    }

    if (og == n)
    {
        printf ("palindrome");
    }
    else
    {
        printf ("not palindrome");
    }

    return 0;
}
