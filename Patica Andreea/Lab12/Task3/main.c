#include <stdio.h>
#include <stdlib.h>

void Hanoi (int n, char from, char to, char aux)
{
    if (n==1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    Hanoi(n-1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    Hanoi(n-1, aux, to, from);
}

int main()
{
    int n;
    scanf("%d", &n);

    Hanoi(n, 'A', 'C', 'B');

    return 0;
}
