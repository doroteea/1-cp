#include <stdio.h>
#include <stdlib.h>
void towerOfHanoi(int n, char fromRod,
                    char toRod, char auxRod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n",fromRod,toRod);
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk &d from rod %c to rod %c\n",n,fromRod,toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n = 3;
    char fromRod='A';
    char auxRod='B';
    char toRod='C';
    towerOfHanoi(n, fromRod, toRod,auxRod);
}
