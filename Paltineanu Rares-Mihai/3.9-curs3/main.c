
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int current = 2019, vect[20], i = 0;
    ///I just dont understand why at the end of the while loop i have a lot of random nr.
    ///I've tried to find something on google, but i didn't find anything
    while(current != 0)
    {
        vect[i++] = current % 2;
        current = current / 2;
    }
    return 0;
}
